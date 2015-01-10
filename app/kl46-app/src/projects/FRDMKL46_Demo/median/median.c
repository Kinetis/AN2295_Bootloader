/**
  Copyright (c) 2006 Freescale Semiconductor
  Freescale Confidential Proprietary
  \file     	median.c
  \brief    	Calculates the median of 8 integer samples 
  \author   	Freescale Semiconductor
  \author       Luis Puebla
  \author   	Guadalajara Applications Laboratory RTAC Americas
  \version    
  \date     	
  \warning    (If needed)

  * History:
  
*/




#include "median.h"


/**
 * \brief   Calculates the median of 8 integer samples
 * \author  Luis Puebla
 * \param   new_value, struct mediana_type *medicion
 * \return   a median value of the last 8 samples
 * \todo
 * \warning
 */ 
int median(int new_value, struct mediana_type *medicion)
{
	int buffer_ord[NUM_OF_SAMPLES_MEDIAN];
  	int i;
  	int temp1;
  	int bandera;
  
  	medicion->ap_muestras++;
  	medicion->ap_muestras &= 0x7;  //de 0 a 7  
  	medicion->sample_buffer[medicion->ap_muestras]=new_value;
	//copia el buffer en temporal  
  	for(i=0;i<8;i++) buffer_ord[i]=medicion->sample_buffer[i];  	
  	//ordena el buffer temporal  
  	do
  	{
   		bandera=0; 
   		for (i=0;i<7;i++)  
   		{
    		if (buffer_ord[i] > buffer_ord[i+1])
     		{
      			temp1 = buffer_ord[i];
      			buffer_ord[i] = buffer_ord[i+1];
      			buffer_ord[i+1] = temp1;
      			bandera=1;  	
     		}	
    	}
  	}
  	
  	while (bandera);   
  	//temp1= (buffer_ord[3] + buffer_ord[4])/2;
       	temp1= buffer_ord[3];
  	return temp1;
 }