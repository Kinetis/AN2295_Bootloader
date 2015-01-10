
/**
  Copyright (c) 2006 Freescale Semiconductor
  Freescale Confidential Proprietary
  \file     	median.h
  \brief    	Calculates the median of 8 integer samples 
  \author   	Freescale Semiconductor
  \author       Luis Puebla
  \author   	Guadalajara Applications Laboratory RTAC Americas
  \version    
  \date     	
  \warning    (If needed)

  * History:
  
*/

#define NUM_OF_SAMPLES_MEDIAN 8

struct mediana_type
  {
 unsigned char   ap_muestras;
 int sample_buffer[NUM_OF_SAMPLES_MEDIAN];
  };

int median(int nuevo_valor, struct mediana_type *medicion);

extern struct mediana_type arr_medianas[];



