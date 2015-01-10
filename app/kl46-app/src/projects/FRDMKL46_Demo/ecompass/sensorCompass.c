
#include "common.h"
#include "arm_cm0.h"
#include "sensorCompass.h"
#include "hal_dev_mag3110.h"
#include "hal_dev_mma8451.h"

#include "median.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

#include "task_mgr.h"

//*****************variables*****************//
// global scalars 

int16 iGpx, iGpy, iGpz;						// raw accelerometer sensor output in bit counts 
int16 iBpx, iBpy, iBpz;						// raw magnetometer sensor output in bit counts 
float fBpx, fBpy, fBpz;						// raw magnetometer data in uT 
float fBcx, fBcy, fBcz;						// mag data in uT after calibration correction 
float fBfx, fBfy, fBfz;						// mag data in uT after tilt correction 
float fGpx, fGpy, fGpz;						// raw accel data in g or m/s2
float fPhi6DOF, fLPPhi6DOF;					// raw and low pass roll angle phi (deg)
float fThe6DOF, fLPThe6DOF;					// raw and low pass pitch angle the (deg)
float fPsi6DOF, fLPPsi6DOF;					// raw and low pass yaw angle psi (deg)
float fRho6DOF, fLPRho6DOF;					// raw and low pass compass angle rho (deg)
float fdelta6DOF, fLPdelta6DOF;				// raw and low pass filtered geomagnetic inclination angle delta (deg) 
int ecompass_direction;

// magnetometer constants //
#define fuTpercount 0.1F			// MAG3110 and FXOS8700 provide 0.1uT per count resolution 
#define fcountsperuT 10.0F			// must be reciprocal of fuTpercount 

// accelerometer constants //
#define fcountsperg 4096.0F			// MMA8451 and FXOS8700 provide 4096 counts per g in 2g mode
#define fgpercount 0.0002441406F	// reciprocal of fcountsperg
#define fms2percount 0.00239502F	// FXOS8700CQ provides 9.81m/s2 per 4096 counts

// general scalars 
int32 validmagcal;					// flag to denote a valid magnetic cal exists 
int32 loopcounter;					// global counter incrementing each iteration of compass 
int32 MagBufferCount;				// number of magnetometer readings in  the magnetic buffer 

// magnetometer measurement buffer
#define MAGBUFFSIZE 5				// dimension in magnetometer buffer: 5 implies 5^3 or 125  
#define miterations 70



struct iMagReading
{
	int16 iBx;		// raw x channel measurement in magnetometer coordinate frame
	int16 iBy;		// raw y channel measurement in magnetometer coordinate frame
	int16 iBz;		// raw z channel measurement in magnetometer coordinate frame
	int32 index;	// time index which increments by 1 each iteration of the eCompass
}; // single measurement entry in magnetometer buffer


struct iMagReading iMagBuff[MAGBUFFSIZE][MAGBUFFSIZE][MAGBUFFSIZE];	// magnetometer measurement buffer


///*******************************
// multiplicative conversion constants 
#define DegToRad 0.01745329251994F	// degrees to radians conversion 
#define RadToDeg 57.2957795130823F	// radians to degrees conversion  
#define frecip180 0.0055555555555F	// multiplicative factor 1/180 

// magnetic calibration constants 
int32 SOLUTIONSIZE;							// calibration model size: 4 or 7 elements 
#define MINEQUATIONS 24						// minimum number of measurements used for calibration 
#define MAXEQUATIONS 96						// maximum number of measurements used for calibration 
#define MINBFIT 5.0F						// minimum acceptable geomagnetic field B for valid calibration
#define MAXBFIT 100.0F						// maximum acceptable geomagnetic field B for valid calibration
#define FITERRORAGING 0.0033333F			// reciprocal of time (s) for fit error to increase by e=2.718 (so here 300s=5 mins)

// flags controlling operation of the algorithms: normally should be TRUE
int32 CALUPDACTIVE = TRUE;					// combined hard and soft iron updating flag
int32 HARDCORRACTIVE = TRUE;				// flag for subtraction of hard iron estimate
int32 SOFTCORRACTIVE = TRUE;				// flag for subtraction of soft iron estimate
int32 TILTCORRACTIVE = TRUE;				// flag for applying tilt correction


// floating point magnetic calibration variables
float fVx, fVy, fVz;							// current computed hard iron calibration in uT 
float xfinvW[3][3], *finvW[3];					// current computed inverse soft iron matrix size 
float fB;										// current computed geomagnetic field magnitude in uT 
float fFitErrorpc;							    // current computed fit error %
float xA[3][3], *A[3];							// ellipsoid matrix A 
float xinvA[3][3], *invA[3];					// inverse of ellipsoid matrix A 
float ftrVx, ftrVy, ftrVz;						// trial computed hard iron calibration in uT 
float xftrinvW[3][3], *ftrinvW[3];				// trial computed inverse soft iron matrix size 
float ftrB;										// trial computed geomagnetic field magnitude in uT 
float ftrFitErrorpc;							// trial computed fit error %
float det;										// matrix determinant

// float orientation matrices 
float xfR6DOFn[3][3], *fR6DOFn[3];			// 6DOF rotation matrix for sample n 
float xfLPR6DOFn[3][3], *fLPR6DOFn[3];		// low pass 6DOF rotation matrix for sample n 
float xfLPR6DOFnm1[3][3], *fLPR6DOFnm1[3];	// low pass 6DOF rotation matrix for sample n-1 

// timing constants
#define FS 50.0F					// eCompass sampling frequency (Hz)
#define DELTAT 0.02F				// eCompass sampling interval (secs), must be reciprocal of FS
#define ANGLE_LPF_FPU 0.0625F		// reciprocal of IR (in samples) of orientation low pass filter so 16 samples 
#define CALINTERVAL 500				// interval in samples for re-computation of the calibration 

// constants to minimise numerical noise in the matrix functions 
#define fmatrixscaling 0.02F	    // approx normalises geomagnetic field 50uT 
#define finvmatrixscaling 50.0F		// inverse of fmatrixscaling

// 7 element float calibration arrays
float xfX7[MAXEQUATIONS][7], *fX7[MAXEQUATIONS];			// matrix of measurements X 
float xftmpA7x7[7][7], *ftmpA7x7[7];						// scratch 7x7 matrix 
float xftmpB7x7[7][7], *ftmpB7x7[7];						// scratch 7x7 matrix 
float xftmpA7x1[7][1], *ftmpA7x1[7];						// scratch 7x1 matrix 

// 4 element float calibration arrays
float xfX4[MAXEQUATIONS][4], *fX4[MAXEQUATIONS];			// matrix of measurements X 
float xfY[MAXEQUATIONS][1], *fY[MAXEQUATIONS];				// 4 element model dependent variables 
float xftmpA4x1[4][1], *ftmpA4x1[4];						// scratch 4x1 matrix 
float xftmpA4x4[4][4], *ftmpA4x4[4];						// scratch 4x4 matrix 
float xftmpB4x1[4][1], *ftmpB4x1[4];						// scratch 4x1 matrix 
float xftmpB4x4[4][4], *ftmpB4x4[4];						// scratch 4x4 matrix

// other float global arrays
float xftmpA3x3[3][3], *ftmpA3x3[3];						// scratch 3x3 matrix 
float xftmpB3x3[3][3], *ftmpB3x3[3];						// scratch 3x3 matrix 
float xftmpA3x1[3][1], *ftmpA3x1[3];						// scratch 3x1 vector 

//#define COORDSYSTEM NED

// coordinate system selected
#define NED 0                       // identifier for NED angle output 
#define ANDROID 1                   // identifier for Android angle output 
#define WIN8 2						// identifier for Windows 8 angle output

int32 COORDSYSTEM;

// orientation quaternions 
//struct fquaternion fqR6DOFn, fqLPR6DOFn;	// current and low pass 6DOF orientation quaternion 
fquaternion fqR6DOFn, fqLPR6DOFn;	// current and low pass 6DOF orientation quaternion 

#define SOLUTIONSIZE 7

extern char tmrFlag;
//int variables
int iPhi6DOF = 0;
int iThe6DOF = 0;
int iPsi6DOF = 0;

//LCD
extern void  vfnLCD_Write_Msg (uint8 *lbpMessage);

//***********************************************************************************************************//




void fSixDOFMyNEDSensorDrivers(void)
{
     // read accel and magnetomertor 
     // accelerometer readings: iGpx , iGpy , iGpz
     // magnetometer readings: iBpx , iBpy , iBpz  
  
      iBpx = iMagReadX();
      iBpy = iMagReadY();
      iBpz = iMagReadZ();
      
      iGpx = iAcclReadX();
      iGpy = iAcclReadY();
      iGpz = iAcclReadZ();

   
      fintToFloatData();
}

void fintToFloatData(void){
  // get float sensor data in units of g and uT
 fGpx = (float) iGpx * fgpercount;
 fGpy = (float) iGpy * fgpercount;
 fGpz = (float) iGpz * fgpercount;
 fBpx = (float) iBpx * fuTpercount;
 fBpy = (float) iBpy * fuTpercount;
 fBpz = (float) iBpz * fuTpercount;
}

// update the magnetic measurement buffer with most recent data 
void fUpdateMagnetometerBuffer(void)
{
	// local variables 
	int32 j, k, l;						// magnetic buffer indices 
	int32 previndex;					// previous time index in the bin being over-written 
	int32 oldestj, oldestk, oldestl;	// indices of bin with oldest data 
	int32 oldestindex;					// time index of bin with oldest data 

	// map -90 to 90 degrees onto range 0 to MAGBUFFSIZE - 1 
	j = (int32) ((atan2(fGpx, fabs(fGpy)) * RadToDeg + 90.0F) * (float) MAGBUFFSIZE * frecip180);
	k = (int32) ((atan2(fGpy, fabs(fGpz)) * RadToDeg + 90.0F) * (float) MAGBUFFSIZE * frecip180);
	l = (int32) ((atan2(fGpz, fabs(fGpx)) * RadToDeg + 90.0F) * (float) MAGBUFFSIZE * frecip180);

	// bounds safety check in case exactly on boundary 
	if (j >= MAGBUFFSIZE) j = MAGBUFFSIZE - 1;		
	if (k >= MAGBUFFSIZE) k = MAGBUFFSIZE - 1;	
	if (l >= MAGBUFFSIZE) l = MAGBUFFSIZE - 1;	

	// save the previous time index in this bin for later use 
	previndex = iMagBuff[j][k][l].index;

	// store the raw short integer magnetometer reading 
	iMagBuff[j][k][l].iBx = iBpx;
	iMagBuff[j][k][l].iBy = iBpy;
	iMagBuff[j][k][l].iBz = iBpz;	

	// set the time index to the loop counter (valid value 0 at start of first pass) 
	iMagBuff[j][k][l].index = loopcounter;

	// no additional action needed if current bin was active but action is needed if bin was inactive (value -1) 
	if (previndex == -1)
	{

		if (MagBufferCount < MAXEQUATIONS)
		{
			// simply increase the count of active measurements for calibration 
			MagBufferCount++;
		}
          
		else
		{
			// we need to find and de-activate the oldest reading 
			oldestindex = loopcounter;
			oldestj = oldestk = oldestl = 0; // to avoid compiler error
			for (j = 0; j < MAGBUFFSIZE; j++)
			{
				for (k = 0; k < MAGBUFFSIZE; k++)
				{
					for (l = 0; l < MAGBUFFSIZE; l++)
					{
						if ((iMagBuff[j][k][l].index != -1) && (iMagBuff[j][k][l].index < oldestindex))
						{
							oldestj = j;
							oldestk = k;
							oldestl = l;
							oldestindex = iMagBuff[oldestj][oldestk][oldestl].index;
						}
					}
				}
			}
			// deactivate the oldest reading without bothering to zero the measurement data
			iMagBuff[oldestj][oldestk][oldestl].index = -1;
		}
	}

	return;
}

// map the uncalibrated magnetometer data Bp (uT) onto calibrated data Bc (uT) 
void fInvertMagCal(void)
{
	// local  variables 
	float ftmpx, ftmpy, ftmpz;

	// remove the computed hard iron offset if enabled 
	if (HARDCORRACTIVE)
	{
		fBcx = fBpx - fVx;
		fBcy = fBpy - fVy;
		fBcz = fBpz - fVz;
	}
	else
	{
		fBcx = fBpx;
		fBcy = fBpy;
		fBcz = fBpz;
	}

	// remove the computed soft iron offset if enabled 
	if (SOFTCORRACTIVE)
	{
		ftmpx = finvW[0][0] * fBcx + finvW[0][1] * fBcy + finvW[0][2] * fBcz;
		ftmpy = finvW[1][0] * fBcx + finvW[1][1] * fBcy + finvW[1][2] * fBcz;
		ftmpz = finvW[2][0] * fBcx + finvW[2][1] * fBcy + finvW[2][2] * fBcz;
		fBcx = ftmpx; 
		fBcy = ftmpy;	
		fBcz = ftmpz;	
	}
	return;
}

// Xtrinsic NED tilt-compensated e-Compass function 
void feCompassNED(float fBx, float fBy, float fBz, float fGx, float fGy, float fGz)
{
	// stack variables 
	// fBx, fBy, fBz: float magnetometer sensor in any units but here uT
	// fGx, fGy, fGz: float accelerometer sensor in any units but here g

	// output 
	// all float eCompass functions, Xtrinsic and Wahba, for all OS (NED, Android and Win) compute 
	// the instantaneous roll, pitch, yaw and compass angles Phi, Theta, Psi and Rho 
	// the instantaneous orientation matrix R6DOFn 
	// the de-rotated magnetic fields Bfx, Bfy, Bfz 
	// the instantaneous rotation quaternion fqR6DOFn 
	// and then call a function to low pass the rotation matrix and obtain the low pass filtered angles 

	// local variables 
	float sinPhi, cosPhi;			// sine and cosine 
	float sinThe, cosThe;			// sine and cosine 
	float sinPsi, cosPsi;			// sine and cosine 
	float rmodG, rmodB;				// reciprocals of moduli of gravitational and magnetic vectors 

	// estimate the declination angle delta (90 minus angle between the vectors) 
	rmodG = 1.0F / (float) sqrt(fGx * fGx + fGy * fGy + fGz * fGz);
	rmodB = 1.0F / (float) sqrt(fBx * fBx + fBy * fBy + fBz * fBz);
	fdelta6DOF = (float) asin((fGx * fBx + fGy * fBy + fGz * fBz) * rmodG * rmodB) * RadToDeg;

	// calculate roll angle Phi (-180deg, 180deg) 
	fPhi6DOF = (float) atan2(fGy,fGz) * RadToDeg;
	sinPhi = (float) sin(fPhi6DOF * DegToRad);  
	cosPhi = (float) cos(fPhi6DOF * DegToRad);

	// de-rotate by roll angle Phi 
	fBfy = fBy * cosPhi - fBz * sinPhi;
	fBz = fBy * sinPhi + fBz * cosPhi;
	fGz = fGy * sinPhi + fGz * cosPhi;

	// check for division by zero and calculate pitch angle Theta (-90deg, 90deg) 
	if (fGz == 0.0F)
	{
		if (fGx >= 0.0F) fThe6DOF = -90.0F;
		else fThe6DOF = 90.0F;
	}
	else
		fThe6DOF = (float)atan(-fGx / fGz) * RadToDeg;
	sinThe = (float) sin(fThe6DOF * DegToRad);	
	cosThe = (float) cos(fThe6DOF * DegToRad);	

	// de-rotate by pitch angle Theta 
	fBfx = fBx * cosThe + fBz * sinThe;
	fBfz = -fBx * sinThe + fBz * cosThe;

	// calculate yaw = ecompass angle Psi (0deg, 360deg) with or without tilt compensation 
	if (TILTCORRACTIVE)
		fPsi6DOF = (float)atan2(-fBfy, fBfx) * RadToDeg; 
	else
		fPsi6DOF = (float)atan2(-fBy, fBx) * RadToDeg; 
	sinPsi = (float) sin(fPsi6DOF * DegToRad);	
	cosPsi = (float) cos(fPsi6DOF * DegToRad);
	if (fPsi6DOF < 0.0F) fPsi6DOF += 360.0F;

	// for NED, the compass heading Rho equals the yaw angle Psi 
	fRho6DOF = fPsi6DOF;

	// calculate the current orientation matrix fR6DOFn 
        //cosPsi = cosThe * cosPsi;
	fR6DOFn[0][0] = cosThe * cosPsi;
	fR6DOFn[0][1] = cosThe * sinPsi;
	fR6DOFn[0][2] = -sinThe;
	fR6DOFn[1][0] = cosPsi * sinThe * sinPhi - cosPhi * sinPsi;
	fR6DOFn[1][1] = cosPhi * cosPsi + sinPhi * sinThe * sinPsi;
	fR6DOFn[1][2] = cosThe * sinPhi; 
	fR6DOFn[2][0] = cosPhi * cosPsi * sinThe + sinPhi * sinPsi;
	fR6DOFn[2][1] = cosPhi * sinThe * sinPsi - cosPsi * sinPhi;
	fR6DOFn[2][2] = cosThe * cosPhi; 

        //**************************************************************************//
	// get the current orientation quaternion 
        
        fQuaternionFromRotationMatrix(fR6DOFn, &fqR6DOFn);

	// apply the low pass filter on the orientation 
	fLPFOrientationMatrix();
        //**************************************************************************//
	return;
}


void fCalibrationUpdate()
{
// try to find an improved calibration if update is enabled     ///CALIBRATION
  if (CALUPDACTIVE)
  {
    // check for enough data in magnetic buffer for a calibration
    if (MagBufferCount >= MINEQUATIONS)
    {
      // calibrate if this will be the first calibration or every CALINTERVAL iterations
      if ((!validmagcal) || (validmagcal && !(loopcounter % CALINTERVAL)))
      {
          // 7 point eigenpair calibration
          if (SOLUTIONSIZE == 7)
          fUpdateCalibration7EIG();
          // 4 point INV calibration
            else if (SOLUTIONSIZE == 4)
            fUpdateCalibration4INV();
              else
                fUpdateCalibration7EIG();
                  // decide if this new calibration should be accepted
                  if ((ftrFitErrorpc <= fFitErrorpc) && (ftrB >= MINBFIT) && (ftrB <= MAXBFIT))
                  {
                    printf("\n\nAccepting new calibration solution\n\n");
                    fFitErrorpc = ftrFitErrorpc;
                    fB = ftrB;
                    fVx = ftrVx;
                    fVy = ftrVy;
                    fVz = ftrVz;
                    fmatrixAeqB(finvW, ftrinvW, 3, 3);
                  }
        else
          {
           printf("\n\nRejecting new calibration solution");
          }
      // age (increase) the calibration fit to avoid a good calibration preventing future updates
      // FITERRORAGING is the reciprocal of the time (s) for the fit error to increase by  e=2.718
      // CALINTERVAL * DELTAT is the interval in seconds between each aging update of fFitErrorpc
      // (1 + FITERRORAGING * CALINTERVAL * DELTAT)^n=e defines n, the number of updates for e fold increase
      // approx n * CALINTERVAL * DELTAT = 1. / FITERRORAGING
      // so as required FITERRORAGING is the reciprocal of the time in secs for e fold increase
      fFitErrorpc += fFitErrorpc * FITERRORAGING * (float) CALINTERVAL * DELTAT;
     } // end of test whether to call calibration functions
    }
    else // still too few entries in magnetic buffer for calibration
      //printf("\r %d entries in magnetometer buffer is too few for calibration", MagBufferCount);  ///**********************************
      printf("\r %d move board to calibrate ", MagBufferCount);  ///**********************************
      CalPercentage ();
   } // end of test for active calibration flag
  /////////////////////////////////////////////////////////////
}

// 7 element calibration using direct eigen-decomposition 
void fUpdateCalibration7EIG(void)
{
	// global working arrays used
	// fX7, ftmpA7x1, ftmpA7x7, ftmpB7x7

	// local variables
	int32 i, j, k, l;						// loop counters 
	float fOffsetx, fOffsety, fOffsetz;		// offset to remove large DC hard iron bias in matrix 
	float ftmpBpx, ftmpBpy, ftmpBpz;		// scratch variables 
	float smallest;							// smallest eigenvalue 

        printf("\n\nThe calibration has ended");
	printf("\n\n7 element EIG calibration at iteration %d with %d in Magnetic Buffer", loopcounter, MagBufferCount);
        

	// the offsets are guaranteed to be set from the first element but to avoid compiler error 
	fOffsetx = fOffsety = fOffsetz = 0.0F;

	// place from MINEQUATIONS to MAXEQUATIONS entries into the measurement matrix 
	i = 0;
	for (j = 0; j < MAGBUFFSIZE; j++)
	{
		for (k = 0; k < MAGBUFFSIZE; k++)
		{
			for (l = 0; l < MAGBUFFSIZE; l++)
			{ 
				if (iMagBuff[j][k][l].index != -1)
				{
					// set tmp to valid data from the magnetic buffer 
					ftmpBpx = (float)iMagBuff[j][k][l].iBx * fuTpercount;
					ftmpBpy = (float)iMagBuff[j][k][l].iBy * fuTpercount;
					ftmpBpz = (float)iMagBuff[j][k][l].iBz * fuTpercount;

					// use first valid magnetic buffer entry as estimate (in uT) for offset to help solution 
					if (i == 0)
					{
						fOffsetx = ftmpBpx;
						fOffsety = ftmpBpy;
						fOffsetz = ftmpBpz;
					}

					// apply the fixed offset and scaling to all measurement vectors for this iteration 
					ftmpBpx = (ftmpBpx - fOffsetx) * fmatrixscaling;
					ftmpBpy = (ftmpBpy - fOffsety) * fmatrixscaling;
					ftmpBpz = (ftmpBpz - fOffsetz) * fmatrixscaling;

					// enter into the measurement matrix X scaling to make entries near unity 
					fX7[i][0] = ftmpBpx * ftmpBpx;
					fX7[i][1] = ftmpBpy * ftmpBpy;
					fX7[i][2] = ftmpBpz * ftmpBpz;
					fX7[i][3] = ftmpBpx;
					fX7[i][4] = ftmpBpy;
					fX7[i][5] = ftmpBpz;
					fX7[i][6] = 1.0F;
					i++;
				}
			}
		}
	}

	// compute the 7x7 matrix ftmpB7x7=fX7^T.fX7 
	fmatrixAeqTrBxC(ftmpB7x7, fX7, fX7, MagBufferCount, 7, 7);

	// set tmpA7x1 to the unsorted eigenvalues and tmpA7x7 to the unsorted eigenvectors of ftmpB7x7=fX7^T.fX7 
	eigencompute(ftmpB7x7, 7, ftmpA7x1, ftmpA7x7);

	// set j to the index of the smallest eigenvalue
	j = 0;
	smallest = ftmpA7x1[0][0];
	for (i = 1; i < 7; i++)
	{
		if (ftmpA7x1[i][0] < smallest)
		{
			j = i;
			smallest = ftmpA7x1[j][0];
		}
	}

	// set ellipsoid matrix A to the solution vector column j with smallest eigenvalue 
	A[0][0] = ftmpA7x7[0][j];
	A[1][1] = ftmpA7x7[1][j];
	A[2][2] = ftmpA7x7[2][j];
	A[0][1] = A[0][2] = A[1][0] = A[1][2] = A[2][0] = A[2][1] = 0.0F;

	// compute the trial hard iron vector in offset bit counts times fmatrixscaling 
	ftrVx = -0.5F * ftmpA7x7[3][j] / A[0][0];
	ftrVy = -0.5F * ftmpA7x7[4][j] / A[1][1];
	ftrVz = -0.5F * ftmpA7x7[5][j] / A[2][2];

	// negate A and gain if A has negative determinant. Sign change cancels for hard iron vector 
	det = A[0][0] * A[1][1] * A[2][2];
	if (det < 0.0F)
	{
		//printf("\n\nEllipsoid matrix A has negative determinant %9.3f so inverting solution", det);
		fmatrixAeqAxScalar(A, -1.0F, 3, 3);
		ftmpA7x7[6][j] = -ftmpA7x7[6][j];
		det = -det;
	}

	// compute the trial geomagnetic field strength B in bit counts times fmatrixscaling 
	ftrB = (float)sqrt(fabs(A[0][0] * ftrVx * ftrVx + A[1][1] * ftrVy * ftrVy + A[2][2] * ftrVz * ftrVz - ftmpA7x7[6][j]));

	// calculate the trial normalised fit error as a percentage 
	ftrFitErrorpc = 100.0F * (float) sqrt(fabs(ftmpA7x1[j][0]) / (double) MagBufferCount) / (2.0F * ftrB * ftrB);
	//printf("\n\nTrial new calibration fit error=%9.4f%% versus previous %9.4f%%", ftrFitErrorpc, fFitErrorpc);

	// correct for the measurement matrix offset and scaling and get the computed trial hard iron offset in uT 
	ftrVx = ftrVx * finvmatrixscaling + fOffsetx;
	ftrVy = ftrVy * finvmatrixscaling + fOffsety;
	ftrVz = ftrVz * finvmatrixscaling + fOffsetz;
	//printf("\n\nTrial new calibration hard iron (uT) Vx=%9.3f Vy=%9.3f Vz=%9.3f", ftrVx, ftrVy, ftrVz);

	// convert the geomagnetic field strength B into uT for current soft iron matrix A 
	ftrB *= finvmatrixscaling;

	// normalise the ellipsoid matrix A to unit determinant and correct B by root of this multiplicative factor 
	fmatrixAeqAxScalar(A, (float)pow((double)det, (double) (-1.0F / 3.0F)), 3, 3);
	ftrB *= (float)pow((double)det, (double) (-1.0F / 6.0F));
	//printf("\n\nTrial new calibration geomagnetic field (uT) B=%9.3f", ftrB);
        
	//printf("\n\nTrial new calibration ellipsoid matrix A (normalized)");
	//fmatrixPrintA(A, 0, 2, 0, 2);

	// compute trial invW from the square root of A also with normalised determinant 
	ftrinvW[0][0] = (float)sqrt(fabs(A[0][0]));
	ftrinvW[1][1] = (float)sqrt(fabs(A[1][1]));
	ftrinvW[2][2] = (float)sqrt(fabs(A[2][2]));
	ftrinvW[0][1] = ftrinvW[0][2] = ftrinvW[1][0] = ftrinvW[1][2] = ftrinvW[2][0] = ftrinvW[2][1] = 0.0F;
	//printf("\n\nTrial new calibration inverse soft iron matrix invW (normalized)");
	//fmatrixPrintA(ftrinvW, 0, 2, 0, 2);

	// for convenience show the original optimal invW 
	//printf("\n\nFor comparison: Simulation inverse soft iron matrix invW (normalized)");  //***********comentados
	//fmatrixPrintA(invSimW, 0, 2, 0, 2);

	// finally set the valid calibration flag to true 
	validmagcal = 1;

	return;
}

// 4 element calibration using 4x4 matrix inverse 
void fUpdateCalibration4INV(void)
{
	// global working arrays used
	// fX4, fY, ftmpB4x4, ftmpA4x1, ftmpB4x1 here and ftmpA4x4, ftmpA4x1 used in f4x4matrixAeqInvSymA

	int32 i, j, k, l;							// loop counters 
	float fOffsetx, fOffsety, fOffsetz;			// offset to remove large DC hard iron bias in matrix 
	float ftmpBpx, ftmpBpy, ftmpBpz;			// scratch variables 
	float fXBeta;								// model fit for a particular measurement 

	printf("\n\n4 element INV calibration at iteration %d with %d in Magnetic Buffer", loopcounter, MagBufferCount);

	// the offsets are guaranteed to be set from the first element but to avoid compiler error 
	fOffsetx = fOffsety = fOffsetz = 0.0F;

	// place from MINEQUATIONS up to MAXEQUATIONS entries into the measurement matrix 
	i = 0;
	for (j = 0; j < MAGBUFFSIZE; j++)
	{
		for (k = 0; k < MAGBUFFSIZE; k++)
		{
			for (l = 0; l < MAGBUFFSIZE; l++)
			{
				if (iMagBuff[j][k][l].index != -1)
				{
					// set tmp to valid data from the magnetic buffer 
					ftmpBpx = (float)iMagBuff[j][k][l].iBx * fuTpercount;
					ftmpBpy = (float)iMagBuff[j][k][l].iBy * fuTpercount;
					ftmpBpz = (float)iMagBuff[j][k][l].iBz * fuTpercount;

					// use first valid magnetic buffer entry as estimate (in uT) for offset to help solution 
					if (i == 0)
					{
						fOffsetx = ftmpBpx;
						fOffsety = ftmpBpy;
						fOffsetz = ftmpBpz;
					}

					// apply the fixed offset and scaling to all measurement vectors for this iteration 
					ftmpBpx = (ftmpBpx - fOffsetx) * fmatrixscaling;
					ftmpBpy = (ftmpBpy - fOffsety) * fmatrixscaling;
					ftmpBpz = (ftmpBpz - fOffsetz) * fmatrixscaling;

					// enter into the measurement matrix X scaling to make entries near unity 
					fX4[i][0] = ftmpBpx;
					fX4[i][1] = ftmpBpy;
					fX4[i][2] = ftmpBpz;
					fX4[i][3] = 1.0F;

					// enter into dependent measurement vector Y 
					fY[i][0] = ftmpBpx * ftmpBpx + ftmpBpy * ftmpBpy + ftmpBpz * ftmpBpz;
					i++;
				}
			}
		}
	}

	// set trial inverse soft iron matrix invW to the identity matrix 
	ftrinvW[0][0] = ftrinvW[1][1] = ftrinvW[2][2] = 1.0F;
	ftrinvW[0][1] = ftrinvW[0][2] = ftrinvW[1][0] = ftrinvW[1][2] = ftrinvW[2][0] = ftrinvW[2][1] = 0.0F;

//********************************************
	 //calculate solution vector ftmpB4x1 = Inv(fX4^T.fX4).fX4^T.Y 
	 fmatrixAeqTrBxC(ftmpB4x4, fX4, fX4, MagBufferCount, 4, 4);	// tmpB4x4 = X^T.X (4x4) 
	 f4x4matrixAeqInvSymA(ftmpB4x4);								// tmpB4x4 = Inv(X^T.X) (4x4) 
	 fmatrixAeqTrBxC(ftmpA4x1, fX4, fY, MagBufferCount, 4, 1);	// tmpA4x1 = X^T.Y (4x1) 
	 fmatrixAeqBxC(ftmpB4x1, ftmpB4x4, ftmpA4x1, 4, 4, 1);		// ftmpB4x1 = Beta = Inv(X^T.X).X^T.Y (4x1)  
//**********************************************
	// calculate the performance function P = (Y-X.Beta)^T.(Y-X.Beta) 
	ftrFitErrorpc = 0.0F;

	// loop over all measurements
	for (i = 0; i < MagBufferCount; i++)
	{
		// calculate the 4 element model fit fXBeta = X.Beta
		fXBeta = fX4[i][0] * ftmpB4x1[0][0] + fX4[i][1] * ftmpB4x1[1][0] + fX4[i][2] * ftmpB4x1[2][0] + ftmpB4x1[3][0];
		ftrFitErrorpc += (fY[i][0] - fXBeta) * (fY[i][0] - fXBeta);
	}

	// calculate the trial normalised fit error (percent) in scaled bit counts but not normalised by B 
	
        ftrFitErrorpc = (float)sqrt(ftrFitErrorpc / MagBufferCount) * 100.0F;

        

	// compute the hard iron vector in offset bit counts times fmatrixscaling 
	ftrVx = 0.5F * ftmpB4x1[0][0];
	ftrVy = 0.5F * ftmpB4x1[1][0];
	ftrVz = 0.5F * ftmpB4x1[2][0];

	// compute the geomagnetic field strength B in bit counts times fmatrixscaling 
	ftrB = (float)sqrt(ftmpB4x1[3][0] + ftrVx * ftrVx + ftrVy * ftrVy + ftrVz * ftrVz);

	// normalise the Fit Error (percent) to the scaled bit count geomagnetic field B 
	ftrFitErrorpc /= (2.0F * ftrB * ftrB); 
	printf("\n\nTrial new calibration fit error=%9.4f%% versus previous %9.4f%%", ftrFitErrorpc, fFitErrorpc);

	// correct for the measurement matrix offset and scaling and get the computed hard iron offset in uT 
	ftrVx = ftrVx * finvmatrixscaling + fOffsetx;
	ftrVy = ftrVy * finvmatrixscaling + fOffsety;
	ftrVz = ftrVz * finvmatrixscaling + fOffsetz;
	printf("\n\nTrial new calibration hard iron (uT) Vx=%9.3f Vy=%9.3f Vz=%9.3f", ftrVx, ftrVy, ftrVz);

	// convert the geomagnetic field strength B into uT 
	ftrB *= finvmatrixscaling;
	printf("\n\nTrial new calibration geomagnetic field (uT) B=%9.3f", ftrB);

	// finally set the valid calibration flag to true 
	validmagcal = 1;

	return;
}

// function copies matrix B to A 
void fmatrixAeqB(float **A, float **B, int32 r, int32 c)
{
	// r = rows in A and B 
	// c = columns in A and B 

	int32 i, j;		// loop counters 

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			A[i][j] = B[i][j];
		}
	}
	return;
} 

// function calculates the matrix product A = B^T x C 
void fmatrixAeqTrBxC(float **A, float **B,  float **C, int32 rBrC, int32 cB, int32 cC)
{
	// rBrC = rows in B before transposing = rows in C 
	// cB = columns in B before transposing 
	// cC = columns in C 
	// A has dimension cB rows x cC columns
	// the matrices B and C can be the same matrix in order to compute B^T x B

	int32 i, j, k;	// counters 

	for (i = 0; i < cB; i++)
	{
		for (j = 0; j < cC; j++)
		{
			A[i][j] = 0.0F;
			for (k = 0; k < rBrC; k++)
				A[i][j] += B[k][i] * C[k][j];
		}
	}
	return;
}

// function computes all eigenvalues and eigenvectors of a real symmetric matrix m[0..n-1][0..n-1] 
// m[][] is unchanged on output 
// eigval[0..n-1] returns the eigenvalues of mat 
// eigvec[0..n-1][0..n-1] is a matrix whose columns contain on output the normalised eigenvectors of m 
// the eigenvectors are not sorted by value 
// the algorithm has complexity n^3 
void eigencompute(float **m, int32 n, float **eigval, float **eigvec)
{   
	// maximum number of iterations to achieve convergence: in practice 6 is typical 
#define NITERATIONS 15		

	// matrix row and column indices
	int32 ir, ic;  
	// general loop counter
	int32 j;
	// various trig functions of the jacobi rotation angle phi
	float cot2phi, tanhalfphi, tanphi, sinphi, cosphi; 
	// scratch variable to prevent over-writing during rotations
	float ftmp;
	// residue from remaining non-zero above diagonal terms
	float residue;
	// timeout ctr for number of passes of the algorithm
	int32 ctr;

	// initialise eigenvectors matrix and eigenvalues array 
	for (ir = 0; ir < n; ir++) 
	{   
		// loop over all columns
		for (ic = 0; ic < n; ic++) 
		{
			// set on diagonal and off-diagonal elements to zero
			eigvec[ir][ic] = 0.0F;   
		}

		// correct the diagonal elements to 1.0
		eigvec[ir][ir] = 1.0F;   

		// initialise the array of eigenvalues to the diagonal elements of m
		eigval[ir][0] = m[ir][ir];   
	}

	// initialise the counter and loop until converged or NITERATIONS reached  
	ctr = 0;
	do
	{   
		// compute the absolute value of the above diagonal elements as exit criterion 
		residue = 0.0F;   
		// loop over rows excluding last row
		for (ir = 0; ir < n - 1; ir++)
		{   
			// loop over above diagonal columns
			for (ic = ir + 1; ic < n; ic++) 
			{
				// accumulate the residual off diagonal terms which are being driven to zero
				residue += fabs(m[ir][ic]); 
			}
		}   

		// check if we still have work to do 
		if (residue > 0.0F) 
		{     
			// loop over all rows with the exception of the last row (since only rotating above diagonal elements)
			for (ir = 0; ir < n - 1; ir++) 
			{   
				// loop over columns ic (where ic is always greater than ir since above diagonal)
				for (ic = ir + 1; ic < n; ic++) 
				{   	
					// only continue with this element if the element is non-zero
					if (fabs(m[ir][ic]) > 0.0F) 
					{   		
						// calculate cot(2*phi) where phi is the Jacobi rotation angle
						cot2phi = 0.5F * (eigval[ic][0] - eigval[ir][0]) / (m[ir][ic]); 

						// calculate tan(phi) correcting sign to ensure the smaller solution is used
						tanphi = 1.0F / (float) (fabs(cot2phi) + sqrt(1.0F + cot2phi * cot2phi));   
						if (cot2phi < 0.0F) 
							tanphi = -tanphi; 

						// calculate the sine and cosine of the Jacobi rotation angle phi
						cosphi = 1.0F / (float)sqrt(1.0F + tanphi * tanphi);  
						sinphi = tanphi * cosphi;   

						// calculate tan(phi/2)
						tanhalfphi = sinphi / (1.0F + cosphi);  

						// set tmp = tan(phi) times current matrix element used in update of leading diagonal elements
						ftmp = tanphi * m[ir][ic];  

						// apply the jacobi rotation to diagonal elements [ir][ir] and [ic][ic] stored in the eigenvalue array
						// eigval[ir] = eigval[ir] - tan(phi) *  m[ir][ic]
						eigval[ir][0] -= ftmp; 
						// eigval[ic] = eigval[ic] + tan(phi) * m[ir][ic]
						eigval[ic][0] += ftmp;   

						// by definition, applying the jacobi rotation on element ir, ic results in 0.0
						m[ir][ic] = 0.0F;   

						// apply the jacobi rotation to all elements of the eigenvector matrix
						for (j = 0; j < n; j++)  
						{
							// store eigvec[j][ir]
							ftmp = eigvec[j][ir];
							// eigvec[j][ir] = eigvec[j][ir] - sin(phi) * (eigvec[j][ic] + tan(phi/2) * eigvec[j][ir])
							eigvec[j][ir] = ftmp - sinphi * (eigvec[j][ic] + tanhalfphi * ftmp);
							// eigvec[j][ic] = eigvec[j][ic] + sin(phi) * (eigvec[j][ir] - tan(phi/2) * eigvec[j][ic])
							eigvec[j][ic] = eigvec[j][ic] + sinphi * (ftmp - tanhalfphi * eigvec[j][ic]);
						} 

						// apply the jacobi rotation only to those elements of matrix m that can change
						for (j = 0; j <= ir - 1; j++) 
						{
							// store m[j][ir]
							ftmp = m[j][ir];
							// m[j][ir] = m[j][ir] - sin(phi) * (m[j][ic] + tan(phi/2) * m[j][ir])
							m[j][ir] = ftmp - sinphi * (m[j][ic] + tanhalfphi * ftmp);
							// m[j][ic] = m[j][ic] + sin(phi) * (m[j][ir] - tan(phi/2) * m[j][ic])
							m[j][ic] = m[j][ic] + sinphi * (ftmp - tanhalfphi * m[j][ic]);
						}
						for (j = ir + 1; j <= ic - 1; j++) 
						{
							// store m[ir][j] 
							ftmp = m[ir][j];
							// m[ir][j] = m[ir][j] - sin(phi) * (m[j][ic] + tan(phi/2) * m[ir][j])
							m[ir][j] = ftmp - sinphi * (m[j][ic] + tanhalfphi * ftmp);
							// m[j][ic] = m[j][ic] + sin(phi) * (m[ir][j] - tan(phi/2) * m[j][ic])
							m[j][ic] = m[j][ic] + sinphi * (ftmp - tanhalfphi * m[j][ic]);	
						}
						for (j = ic + 1; j < n; j++) 
						{
							// store m[ir][j] 
							ftmp = m[ir][j];
							// m[ir][j] = m[ir][j] - sin(phi) * (m[ic][j] + tan(phi/2) * m[ir][j])
							m[ir][j] = ftmp - sinphi * (m[ic][j] + tanhalfphi * ftmp);
							// m[ic][j] = m[ic][j] + sin(phi) * (m[ir][j] - tan(phi/2) * m[ic][j])
							m[ic][j] = m[ic][j] + sinphi * (ftmp - tanhalfphi * m[ic][j]);
						}	
					}   // end of test for matrix element already zero
				}   // end of loop over columns 
			}   // end of loop over rows
		}  // end of test for non-zero residue
	} while ((residue > 0.0F) && (ctr++ < NITERATIONS)); // end of main loop

	// recover the above diagonal matrix elements from unaltered below diagonal elements 
	for (ir = 0; ir < n - 1; ir++)
	{
		// loop over above diagonal columns
		for (ic = ir + 1; ic < n; ic++)
		{
			// copy below diagonal element to above diagonal element
			m[ir][ic] = m[ic][ir];
		}
	}
	return;
}  

// function multiplies all elements of matrix A by the specified scalar 
void fmatrixAeqAxScalar(float **A, float Scalar, int32 r, int32 c)
{
	// r = rows and c = columns in A 

	int32 i, j;		// loop counters 

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			A[i][j] *= Scalar;
		}
	}
	return;
}


// function prints the floating point matrix A between rows r1 and r2 and columns c1 and c2 inclusve 
void fmatrixPrintA(float **A, int32 r1, int32 r2, int32 c1, int32 c2)
{
	int32 i, j;		// loop counters 

	for (i = r1; i <= r2; i++)
	{
		printf("\nRow %d", i);
		for (j = c1; j <= c2; j++)
		{
			printf("%12.5f", (double) A[i][j]);
		}
	}
	return;
}

// (FLOAT) function computes inverse of a symmetric 4x4 matrix A
void f4x4matrixAeqInvSymA(float **A)
{
	// global arrays used: ftmpA4x1, ftmpA4x4

	// local variables
	int32 i, j, k;		// loop counters
	float fdet;			// matrix determinant

	// set tmpA4x1 to the eigenvalues and tmpA4x4 to the eigenvectors of A
	// function eigencompute does not use any additional global arrays
	eigencompute(A, 4, ftmpA4x1, ftmpA4x4);

	// check if the matrix A is singular by computing its determinant from the product of its eigenvalues
	fdet = 1.0F;
	for (i = 0; i < 4; i++)
		fdet *= ftmpA4x1[i][0];

	// compute the inverse if the determinant is non-zero
	if (fdet != 0.0F)
	{
		// take the reciprocal of the eigenvalues
		for (i = 0; i < 4; i++)
			ftmpA4x1[i][0] = 1.0F / ftmpA4x1[i][0];

		// set A to be eigenvectors . diag(1.0F / eigenvalues) . eigenvectors^T
		for (i = 0; i < 4; i++) // loop over rows i
		{
			for (j = 0; j < 4; j++) // loop over columns j
			{
				A[i][j] = 0.0F;
				for (k = 0; k < 4; k++)
				{
					A[i][j] += ftmpA4x4[i][k] * ftmpA4x1[k][0] * ftmpA4x4[j][k];
				}
			}
		}
	}
	else
	{
		// the matrix A is singular so return the identity matrix
		fmatrixAeqI(A, 4);
	}

	return;
}

// function calculates the matrix product A = B x C 
void fmatrixAeqBxC(float **A, float **B, float **C, int32 rB, int32 cBrC, int32 cC)
{
	// rB = rows in B 
	// cBrC = columns in B = rows in C 
	// cC = columns in C 
	// A has dimension rB rows x cC columns 

	int32 i, j, k;	// counters 

	for (i = 0; i < rB; i++)
	{
		for (j = 0; j < cC; j++)
		{
			A[i][j] = 0.0F;
			for (k = 0; k < cBrC; k++)
				A[i][j] += B[i][k] * C[k][j]; 
		}
	}
	return;
}

// function sets the matrix A to the identity matrix 
void fmatrixAeqI(float **A, int32 rc)
{
	// rc = rows and columns in A 

	int32 i, j;		// loop counters 

	for (i = 0; i < rc; i++)
	{
		for (j = 0; j < rc; j++)
		{
			A[i][j] = 0.0F;
		}
		A[i][i] = 1.0F;
	}
	return;
}

void fLPFOrientationMatrix()
{
	// function is called after eCompass and will always have a valid orientation matrix fR6DOFn 
	// function low pass filters the orientation matrix fLPR6DOFn and updates fLPR6DOFnm1 
	// low roll (phi), pitch (the), yaw (psi) and compass (rho) are computed from the low pass matrix 
	// computes the low pass filtered orientation quaternion fqLPR6DOFn 
	// and the inclination angle delta is low pass filtered 

	// local variables 
	float ftmpAngle;			// scratch variable 

	// on first pass initialise low pass filtered rotation matrix to current 
	if (loopcounter == 0)
	{
		fmatrixAeqB(fLPR6DOFn, fR6DOFn, 3, 3);
		fLPdelta6DOF = fdelta6DOF;
	}

	// shuffle low pass filtered matrix down the delay line 
	fmatrixAeqB(fLPR6DOFnm1, fLPR6DOFn, 3, 3);

	// exponentially filter the orientation matrix fLPR6DOFn towards fR6DOFn 
	// set ftmpA3x3 to dR = R6[n].LPR6[n]^T 
	fmatrixAeqBxTrC(ftmpA3x3, fR6DOFn, fLPR6DOFn, 3, 3, 3);
	// set ftmpA3x1 to the rotation axis and ftmp to the angle change 
	ftmpAngle = 0.0F; // to avoid compiler error
	fAxisAngleDegFromRotationMatrix(ftmpA3x3, ftmpA3x1, &ftmpAngle);
	// set ftmpA3x3 to the matrix required to exponentially converge the low pass matrix to current 
	fRotationMatrixFromAxisAngleDeg(ftmpA3x3, ftmpA3x1, ftmpAngle * ANGLE_LPF_FPU);
	// rotate the low pass filtered orientation matrix fLPR6DOFn by the required amount 
	fmatrixAeqBxC(ftmpB3x3, ftmpA3x3, fLPR6DOFn, 3,  3, 3);
	fmatrixAeqB(fLPR6DOFn, ftmpB3x3, 3, 3);

	// calculate the low pass quaternion from the low pass filtered rotation matrix 
	//fQuaternionFromRotationMatrix(fLPR6DOFn, &fqLPR6DOFn);

	// calculate the low pass filtered angles from the low pass filtered orientation matrix 
	if (COORDSYSTEM == NED) // NED
	{
		// get the low pass filtered angles 
		fNEDAnglesDegFromRotationMatrix(fLPR6DOFn, &fLPPhi6DOF, &fLPThe6DOF, &fLPPsi6DOF, &fLPRho6DOF);
		// recompute the matrix from the angles to stop error propagation 
		fNEDRotationMatrixFromAnglesDeg(fLPR6DOFn, fLPPhi6DOF, fLPThe6DOF, fLPPsi6DOF);
	}
//	else if (COORDSYSTEM == ANDROID) // Android
//	{
//		// get the low pass filtered angles 
//		fAndroidAnglesDegFromRotationMatrix(fLPR6DOFn, &fLPPhi6DOF, &fLPThe6DOF, &fLPPsi6DOF, &fLPRho6DOF);
//		// recompute the matrix from the angles to stop error propagation 
//		fAndroidRotationMatrixFromAnglesDeg(fLPR6DOFn, fLPPhi6DOF, fLPThe6DOF, fLPPsi6DOF);
//	}
//	else // Windows 8 
//	{
//		// get the low pass filtered angles 
//		fWin8AnglesDegFromRotationMatrix(fLPR6DOFn, &fLPPhi6DOF, &fLPThe6DOF, &fLPPsi6DOF, &fLPRho6DOF);
//		// recompute the matrix from the angles to stop error propagation 
//		fWin8RotationMatrixFromAnglesDeg(fLPR6DOFn, fLPPhi6DOF, fLPThe6DOF, fLPPsi6DOF);
//	}

	// exponentially low pass filter the inclination angle 
	ftmpAngle = fdelta6DOF - fLPdelta6DOF;
	if (ftmpAngle > 180.0F) ftmpAngle -= 360.0F;
	if (ftmpAngle < -180.0F) ftmpAngle += 360.0F;
	fLPdelta6DOF += ANGLE_LPF_FPU * ftmpAngle;

	return;
}

// function calculates the matrix product A = B x C^T 
void fmatrixAeqBxTrC(float **A, float **B, float **C, int32 rB, int32 cBcC, int32 rC)
{
	// rB = rows in B 
	// cBcC = columns in B = columns in C 
	// rC = rows in C 
	// A has dimension rB rows x rC columns 

	int32 i, j, k;	// counters 

	for (i = 0; i < rB; i++)
	{
		for (j = 0; j < rC; j++)
		{
			A[i][j] = 0.0F;
			for (k = 0; k < cBcC; k++)
				A[i][j] += B[i][k] * C[j][k]; 
		}
	}
	return;
}

// compute the normalised rotation axis and angles from a rotation matrix 
void fAxisAngleDegFromRotationMatrix(float **R, float **n, float *pfeta)
{
	float ftrace;				// trace of the rotation matrix 
	float fscale;				// scale factor to normalise rotation axis vector 

	// calculate the trace of the rotation matrix = 1+2cos(eta) 
	ftrace = R[0][0] + R[1][1] + R[2][2];

	// calculate differences across the diagonal = 2*n*sin(eta) giving null vector for 0 and 180 deg 
	n[0][0] = R[1][2] - R[2][1]; 
	n[1][0] = R[2][0] - R[0][2]; 
	n[2][0] = R[0][1] - R[1][0];
	fscale = (float)sqrt(n[0][0] * n[0][0] + n[1][0] * n[1][0] + n[2][0] * n[2][0]);

	// normal case when the vector is not zero and the angle is not 0 or 180 deg 
	if (fscale != 0.0F)
	{
		// normalise the unit vector with previously stored differences 
		fscale = 1.0F / fscale;
		n[0][0] *= fscale;
		n[1][0] *= fscale;
		n[2][0] *= fscale;

		// calculate the rotation angle eta in the range 0 to 180 degrees 
		if (ftrace >= 3.0F) *pfeta = 0.0F;
		else if (ftrace <= -1.0F) *pfeta = 180.0F;
		else *pfeta = (float)acos(0.5F * (ftrace - 1.0F)) * RadToDeg;

		return;
	}

	// if positive trace (actually trace = 3) then it's zero deg rotation 
	if (ftrace > 0.0F)
	{
		// choose an arbitrary normalised rotation axis here x 
		n[0][0] = 1.0F;
		n[1][0] = n[2][0] = 0.0F;
		// and set the rotation angle eta to zero 
		*pfeta = 0.0F;

		return;
	}

	// finally it must be a rotation of 180 deg (with trace = -1) with two possible axis directions 
	// we can arbitrarily select n[0] to be non-negative 
	n[0][0] = (float)sqrt(fabs(0.5F * (R[0][0] + 1.0F)));
	// use the sign of R[0][1]=2*nx*ny to determine the sign of the y component 
	if (R[0][1] >= 0.0F)
		n[1][0] = (float)sqrt(fabs(0.5F * (R[1][1] + 1.0F)));
	else
		n[1][0] = (float)-sqrt(fabs(0.5F * (R[1][1] + 1.0F)));
	// use the sign of R[0][2]=2*nx*ny to determine the sign of the z component 
	if (R[0][2] >= 0.0F)
		n[2][0] = (float)sqrt(fabs(0.5F * (R[2][2] + 1.0F)));
	else
		n[2][0] = (float)-sqrt(fabs(0.5F * (R[2][2] + 1.0F)));
	// the resulting rotation axis is normalised 
	// set the rotation angle eta to 180 degrees 
	*pfeta = 180.0F;

	return;
}

// calculate a rotation matrix from the rotation axis and angles 
void fRotationMatrixFromAxisAngleDeg(float **R, float **n, float feta)
{
	float fsineta, fcoseta;		// sin(eta) and cos(eta) 
	float f1mcoseta;			// 1.-cos(eta) 
	float ftmp;					// scratch variable

	// for safety, provide identity matrix (zero rotation) if null axis is specified 
	if ((n[0][0] == 0.0F) && (n[1][0] == 0.0F) && (n[2][0] == 0.0F))
	{
		R[0][0] = R[1][1]= R[2][2] = 1.0F;
		R[0][1] = R[0][2] = R[1][0] = R[1][2] = R[2][0] = R[2][1] = 0.0F;
	}
	else
	{
		// calculate the sine and cosine of the rotation angle 
		fsineta = (float)sin(feta * DegToRad);
		fcoseta = (float)cos(feta * DegToRad);
		f1mcoseta = 1.0F - fcoseta;

		// for safety, normalise the rotation axis 
		ftmp = 1.0F / (float)sqrt(n[0][0] * n[0][0] + n[1][0] * n[1][0] + n[2][0] * n[2][0]);
		n[0][0] *= ftmp;
		n[1][0] *= ftmp;
		n[2][0] *= ftmp;

		// construct the remaining elements of the rotation matrix 
		R[0][0] = n[0][0] * n[0][0] * f1mcoseta + fcoseta;
		R[1][1] = n[1][0] * n[1][0] * f1mcoseta + fcoseta;
		R[2][2] = n[2][0] * n[2][0] * f1mcoseta + fcoseta;
		R[0][1] = n[0][0] * n[1][0] * f1mcoseta + n[2][0] * fsineta;
		R[1][0] = n[0][0] * n[1][0] * f1mcoseta - n[2][0] * fsineta;
		R[0][2] = n[0][0] * n[2][0] * f1mcoseta - n[1][0] * fsineta;
		R[2][0] = n[0][0] * n[2][0] * f1mcoseta + n[1][0] * fsineta;
		R[1][2] = n[1][0] * n[2][0] * f1mcoseta + n[0][0] * fsineta;
		R[2][1] = n[1][0] * n[2][0] * f1mcoseta - n[0][0] * fsineta;
	}

	return;
}

// extract the NED angles in degrees from the NED rotation matrix 
void fNEDAnglesDegFromRotationMatrix(float **R, float *pfPhiDeg, float *pfTheDeg, float *pfPsiDeg, float *pfRhoDeg)
{
	// calculate the pitch angle range -90 to 90 degrees 
	if (R[0][2] >= 1.0F)
		*pfTheDeg = -90.0F;
	else if (R[0][2] <= -1.0F)
		*pfTheDeg = 90.0F;
	else
		*pfTheDeg = (float) asin(-R[0][2]) * RadToDeg;

	// calculate the roll angle range -180 to 180 degrees 
	*pfPhiDeg = (float)atan2(R[1][2], R[2][2]) * RadToDeg;

	// calculate the yaw and compass angle rangle 0 to 360 degrees 
	*pfPsiDeg = (float)atan2(R[0][1], R[0][0]) * RadToDeg; 
	if (*pfPsiDeg < 0.0F)
		*pfPsiDeg += 360.0F;
	*pfRhoDeg = *pfPsiDeg;

	return;
}


// construct a NED rotation matrix from the NED Euler angles in degrees 
void fNEDRotationMatrixFromAnglesDeg(float **R, float fPhiDeg, float fTheDeg, float fPsiDeg)
{
	float sinPhi, cosPhi, sinThe, cosThe, sinPsi, cosPsi;		// sines and cosines 

	// calculate the sines and cosines
	sinPhi = (float) sin(fPhiDeg * DegToRad);
	sinThe = (float) sin(fTheDeg * DegToRad);
	sinPsi = (float) sin(fPsiDeg * DegToRad);
	cosPhi = (float) cos(fPhiDeg * DegToRad);
	cosThe = (float) cos(fTheDeg * DegToRad);
	cosPsi = (float) cos(fPsiDeg * DegToRad);

	// construct the matrix
	R[0][0] = cosThe * cosPsi;
	R[0][1] = cosThe * sinPsi;
	R[0][2] = -sinThe;
	R[1][0] = cosPsi * sinThe * sinPhi - cosPhi * sinPsi;
	R[1][1] = cosPhi * cosPsi + sinPhi * sinThe * sinPsi;
	R[1][2] = cosThe * sinPhi; 
	R[2][0] = cosPhi * cosPsi * sinThe + sinPhi * sinPsi;
	R[2][1] = cosPhi * sinThe * sinPsi - cosPsi * sinPhi;
	R[2][2] = cosThe * cosPhi;

	return;
}

// compute the orientation quaternion from a rotation matrix 
void fQuaternionFromRotationMatrix(float **R,  fquaternion *pq)
{
	float foneplustrace;		// 1+trace of the rotation matrix 
	float fscale;				// temporary scale factor 

	// calculate one plus the trace of the rotation matrix = 4*q0*q0 
	foneplustrace = 1.0F + R[0][0] + R[1][1] + R[2][2];

	// normal case when q0 is not zero 
	if (foneplustrace > 0.0F)
	{
		// calculate q0 to q3
		pq->q0 = 0.5F * (float)sqrt(foneplustrace); // q0 guaranteed non-negative
		fscale = 1.0F / pq->q0;
		pq->q1 = 0.25F * fscale * (R[1][2] - R[2][1]); 
		pq->q2 = 0.25F * fscale * (R[2][0] - R[0][2]); 
		pq->q3 = 0.25F * fscale * (R[0][1] - R[1][0]);

		return;
	}

	// otherwise q0 is zero meaning 180 deg rotation 
	pq->q0 = 0.0F;
	pq->q1 = (float)sqrt(fabs(0.5F + 0.5F * R[0][0])); 
	pq->q2 = (float)sqrt(fabs(0.5F + 0.5F * R[1][1])); 
	pq->q3 = (float)sqrt(fabs(0.5F + 0.5F * R[2][2])); 

	// correct sign ambiguities in q2 and q3 given q1 is assumed non-negative 
	if (R[0][1] < 0.0F) pq->q2 = -pq->q2;
	if (R[0][2] < 0.0F) pq->q3 = -pq->q3;

	return;
}

void ResetMagCalibrationFunc(void)
{
	int32 j, k, l;   // loop counters  

	// initialise the calibration hard and soft iron estimate to null 
	fmatrixAeqI(finvW, 3);
	fVx = fVy = fVz = 0.;
	fB = 0.0F;
	fFitErrorpc = 1000.0F; 
	validmagcal = 0;

	// set the loop counter to 0 to denote first pass 
	loopcounter = 0;

	// set magnetic buffer index to invalid value -1 to denote invalid
	MagBufferCount = 0;
	for (j = 0; j < MAGBUFFSIZE; j++)
		for (k = 0; k < MAGBUFFSIZE; k++)
			for (l = 0; l < MAGBUFFSIZE; l++)
				iMagBuff[j][k][l].index = -1;

	return;
}



 int ErrFlag = 0;;
 uint16 average = 40;
 uint8 averageCounter = 0;
 uint16 calCounter = 0;
 int APhi6DOF, AThe6DOF, APsi6DOF; 
 char buffer[10];

void ControlLoopCompass(void) 
{
 
  
     //printf("\n");
  
  
 // for (i = 0; i < miterations; i++)
 // {

 // call sensor driver simulation to get accel and mag data in integer counts 	
    fSixDOFMyNEDSensorDrivers(); 

// update the magnetometer measurement buffer integer magnetometer data
    fUpdateMagnetometerBuffer();

// remove hard and soft iron terms from Bp (uT) to get calibrated data Bc (uT) 
    fInvertMagCal();

// NED coordinate system
    feCompassNED(fBcx, fBcy, fBcz, fGpx, fGpy, fGpz);
		
    Conversion();
     if (validmagcal !=0)
    {
     APhi6DOF = median(iPhi6DOF, &arr_medianas[0]);
     AThe6DOF = median(iThe6DOF, &arr_medianas[1]);
     APsi6DOF = median(iPsi6DOF, &arr_medianas[2]);
    //    printf("Yaw =%4d Pitch =%4d Roll =%4d \r", APhi6DOF, AThe6DOF, APsi6DOF);
     APsi6DOF = 359 - APsi6DOF;
     
     sprintf(buffer,"%04d",APsi6DOF);
     vfnLCD_Write_Msg(buffer);   //print when it is calibrated
     ecompass_direction = APsi6DOF;
    }
// try to find an improved calibration if update is enabled 
  else 
    {  
     fCalibrationUpdate();
    }
    loopcounter++;
   
 // } 
  

}



void eCompassInit(void)
{
	
  	int32 i;							// loop counter 
	//int32 niterations;					// number of eCompass iterations to be performed 
    //     printf("\n\n eCompass Initialization\n");
   //      printf("\n\n Taking measurements for Calibration\n\n Move Constantly the Board until Calibration ends");
         
    
   //printf("\n\nTrial new calibration geomagnetic field (uT) B=%9.3f", ftrB);
	// apply the tweak for C's limitation on functions receiving variable size arrays 
	// 3 row arrays used by all calibration models
	for (i = 0; i < 3; i++)
	{
		//invSimW[i] = xinvSimW[i]; 	
		//SimW[i] = xSimW[i];
		finvW[i] = xfinvW[i];
		ftrinvW[i] = xftrinvW[i];
		A[i] = xA[i];
		invA[i] = xinvA[i];
		ftmpA3x3[i] = xftmpA3x3[i];
		ftmpB3x3[i] = xftmpB3x3[i];
		ftmpA3x1[i] = xftmpA3x1[i];
		fR6DOFn[i] = xfR6DOFn[i];
		fLPR6DOFn[i] = xfLPR6DOFn[i];
		fLPR6DOFnm1[i] = xfLPR6DOFnm1[i];
	}
	// 4 row arrays for 4 element float calibration
	for (i = 0; i < 4; i++)
	{
		ftmpB4x1[i] = xftmpB4x1[i];
		ftmpA4x1[i] = xftmpA4x1[i];
		ftmpA4x4[i] = xftmpA4x4[i];
		ftmpB4x4[i] = xftmpB4x4[i];
	}
	// 7 row arrays for 7 element float calibration
	for (i = 0; i < 7; i++)
	{
		ftmpA7x7[i] = xftmpA7x7[i];	
		ftmpB7x7[i] = xftmpB7x7[i];	
		ftmpA7x1[i] = xftmpA7x1[i];	
	}
	// MAXEQUATIONS row arrays of measurements
	for (i = 0; i < MAXEQUATIONS; i++)
	{
		fX7[i] = xfX7[i];		// 7 element float calibration
		fX4[i] = xfX4[i];		// 4 element float calibration
		fY[i] = xfY[i];			// 4 element float calibration
	} 


	// reset computed magnetic calibration and magnetometer data buffer and gyro calibration  
	    ResetMagCalibrationFunc(); 

}
/*
  convert float to integer

    phi, The, Psi
*/

void Conversion (void) {
  iPhi6DOF = (int) fPhi6DOF; 
  iThe6DOF = (int) fThe6DOF;
  iPsi6DOF = (int) fPsi6DOF;
}
/*
   Calibration status percentage

*/
void CalPercentage (void) {
    int iVarPercentage = 0;
    char buffer[10];
    iVarPercentage = (MagBufferCount*100)/MINEQUATIONS;
    sprintf(buffer,"C%03d",iVarPercentage);
    vfnLCD_Write_Msg(buffer);
}
