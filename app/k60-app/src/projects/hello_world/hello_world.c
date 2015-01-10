/*
 * File:		hello_world.c
 * Purpose:		Main process
 *
 */

#include "common.h"

/********************************************************************/
void main (void)
{
	char ch;
                
  	printf("\nHello World!!\n");

	while(1)
	{
		ch = in_char();
		out_char(ch);
                
	} 
}
/********************************************************************/
