/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2013-2014 Freescale Semiconductor, Inc.
* ALL RIGHTS RESERVED.
*
***************************************************************************//*!
*
* @file crc.c
*
* @author Freescale
*
* @version 0.0.1
*
* @date Apr 19, 2013
*
* @brief application entry point which performs application specific tasks. 
*
*******************************************************************************
*
* provide a demo for how to initialize the MKE02, output messages via SCI, 
* flash operations, etc.
* NOTE:
*	printf call may occupy a lot of memory (around 1924 bytes), so please
*	consider your code size before using printf.
******************************************************************************/
#include "common.h"
#include "crc.h"
/********************************************************************/
/*#define BYTE_ENABLES_7_E*/
/*#define BYTE_ENABLES_3_6_C*/
/*#define BYTE_ENABLES_1_2_4_8*/
/********************************************************************/
/*FUNCTION****************************************************************
* 
* Function Name    : CRC_Config
* Returned Value   : CRC Configuration Result
* Comments         :
*    brief configure CRC with specified options.
*
*END*********************************************************************/
int CRC_Config (uint32 poly,uint32 tot,uint32 totr,uint32 fxor,uint32 tcrc)
{
    uint32 ctrl_reg;
    int error = CRC_ERR_SUCCESS;
    /*Configure CRC_CTRL Register*/
    if( tot > 3 ) {
        error = CRC_ERR_TOT_VAL;
    }
    else if( totr > 3 ) {
        error = CRC_ERR_TOTR_VAL;
    }
    else if( fxor > 1 ) {
        error = CRC_ERR_FXOR_VAL;
    }
    else if( tcrc > 1 ) {
        error = CRC_ERR_TCRC_VAL;
    } 
    else {
        ctrl_reg=(tot<<30)|(totr<<28)|(fxor<<26)|(tcrc<<24);
        CRC_CTRL=ctrl_reg;
    } 
    /*Configure Polynomial Register*/
    CRC_GPOLY=poly; 
    return(error);
}

/*FUNCTION****************************************************************
* 
* Function Name    : CRC_Cal_16
* Returned Value   : CRC16 Calculation Result
* Comments         :
*    16bit data CRC Calculation
*
*END*********************************************************************/
uint32 CRC_Cal_16(uint32 seed,uint8 *msg, uint32 sizeBytes)
{
    uint32 ctrl_reg,data_out,data_in;
    uint8  *pCRCBytes;
    uint32 sizeWords;
    uint32 i,j;  
    /*Input seed, Set WaS=1*/
    ctrl_reg=CRC_CTRL;
    CRC_CTRL=ctrl_reg | 0x02000000;
    CRC_DATA=seed; 
    /*Input data, Set WaS=0*/
    CRC_CTRL=ctrl_reg & 0xFD000000;
    /*Wait for calculation completion*/
    sizeWords = sizeBytes>>1;
    j = 0;
    for(i=0;i<sizeWords;i++){ 
        data_in = (msg[j] << 8) | (msg[j+1]);
        j += 2;
        CRC_DATAL=data_in; 
    }
    if(j<sizeBytes)
    { 
        pCRCBytes = (uint8*)&CRC_DATA;
        *pCRCBytes++ = msg[j];
    }
    data_out=CRC_DATA;
    
    return(data_out);
}


/*FUNCTION****************************************************************
* 
* Function Name    : CRC_Cal_32
* Returned Value   : CRC32 Calculation result
* Comments         :
*    32bit data CRC Calculation
*
*END*********************************************************************/
uint32 CRC_Cal_32(uint32 seed,uint8 *msg, uint32 sizeBytes)
{
    uint32 ctrl_reg,data_out,data_in;
    uint32 sizeDwords;
    uint8  *pCRCBytes;
    int i,j;
    /*Input seed, Set WaS=1*/
    ctrl_reg=CRC_CTRL;
    CRC_CTRL=ctrl_reg|0x02000000;
    CRC_DATA=seed;
    
    /*Input data, Set WaS=0*/
    CRC_CTRL=ctrl_reg&0xFD000000;
    
    /* Wait for calculation completion*/
    sizeDwords = sizeBytes>>2;
    j = 0;
    for(i=0;i<sizeDwords;i++){ 
        data_in = ((msg[j] << 24) | (msg[j+1] << 16) | (msg[j+2] << 8) | msg[j+3]);
        j += 4;
        CRC_DATA = data_in; 
    }
    if(j<sizeBytes)
    {
        pCRCBytes = (uint8*)&CRC_DATA;
        
#ifdef  defined(BYTE_ENABLES_1_2_4_8)                     /*write single byte */ 
        for(;j<sizeBytes;j++)
        {     
            *pCRCBytes++ = msg[j];
        }
#elif  defined(BYTE_ENABLES_3_6_C)                        /*write two bytes*/
        data_in = 0;
        i = 0;
        for(;j<sizeBytes;j++)
        {     
            data_in = (data_in <<8) | msg[j];
            i++;
            if(i==2)
            {
                i = 0;
                CRC_DATAL = data_in;
            }
        }
        if(i==1)
        {
            CRC_CRC_LL = data_in;                        /*write last byte*/
        }
#elif  defined(BYTE_ENABLES_7_E)                         /*write three bytes*/
        data_in = 0;
        i = 0;
        for(;j<sizeBytes;j++)
        {     
            data_in = (data_in <<8) | msg[j];
            i++;
            if(i==3)
            {
                i = 0;
                // write first  char
                CRC_DATAHL  = (data_in>>16) & 0xff;      /*write low byte of high word*/
                // write last two chars
                CRC_DATAL = data_in & 0x00ffff;          /* write low word*/
            }
        }
        if( i == 2)
        {
            CRC_DATAL = (data_in);                       /*write last byte*/
        }
        else if (i == 1)
        {
            CRC_CRC_LL = data_in;                        /*write last byte*/      
        }
#else                                                    /*write low byte only*/
        for(;j<sizeBytes;j++)
        {     
            *pCRCBytes = msg[j];
        }
#endif            
    }
    data_out=CRC_DATA;
    
    return(data_out);
}
/********************************************************************/ 
