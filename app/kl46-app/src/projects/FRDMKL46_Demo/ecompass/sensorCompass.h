



typedef struct
{
	float q0;	// scalar component
	float q1;	// x vector component
	float q2;	// y vector component
	float q3;	// z vector component
} fquaternion; 


void fSixDOFMyNEDSensorDrivers(void);
void fintToFloatData(void);
void fUpdateMagnetometerBuffer(void);
void fInvertMagCal(void);
void feCompassNED(float fBx, float fBy, float fBz, float fGx, float fGy, float fGz);
void fCalibrationUpdate(void);
void fUpdateCalibration7EIG(void);
void fUpdateCalibration4INV(void);
void fmatrixAeqB(float **A, float **B, int32 r, int32 c);
void fmatrixAeqTrBxC(float **A, float **B,  float **C, int32 rBrC, int32 cB, int32 cC);
void eigencompute(float **m, int32 n, float **eigval, float **eigvec);
void fmatrixAeqAxScalar(float **A, float Scalar, int32 r, int32 c);
void fmatrixPrintA(float **A, int32 r1, int32 r2, int32 c1, int32 c2);
void f4x4matrixAeqInvSymA(float **A);
void fmatrixAeqBxC(float **A, float **B, float **C, int32 rB, int32 cBrC, int32 cC);
void fmatrixAeqI(float **A, int32 rc);
void fLPFOrientationMatrix(void);
void fmatrixAeqBxTrC(float **A, float **B, float **C, int32 rB, int32 cBcC, int32 rC);
void fAxisAngleDegFromRotationMatrix(float **R, float **n, float *pfeta);
void fRotationMatrixFromAxisAngleDeg(float **R, float **n, float feta);
void fNEDAnglesDegFromRotationMatrix(float **R, float *pfPhiDeg, float *pfTheDeg, float *pfPsiDeg, float *pfRhoDeg);
void fNEDRotationMatrixFromAnglesDeg(float **R, float fPhiDeg, float fTheDeg, float fPsiDeg);
void fQuaternionFromRotationMatrix(float **R,  fquaternion *pq);
void ControlLoopCompass(void);
void eCompassInit(void);
void Conversion (void);
void CalPercentage (void);


//extern prototypes//
extern int iMagReadX(void);
extern int iMagReadY(void);
extern int iMagReadZ(void);
extern int iAcclReadX(void);
extern int iAcclReadY(void);
extern int iAcclReadZ(void);



extern void task_read_ecompass(void);
extern void task_ecompass_calibrate(void);

extern int ecompass_direction;

extern  int APhi6DOF, AThe6DOF, APsi6DOF; 

extern int16 iGpx, iGpy, iGpz;						// raw accelerometer sensor output in bit counts 
extern int16 iBpx, iBpy, iBpz;						// raw magnetometer sensor output in bit counts 
