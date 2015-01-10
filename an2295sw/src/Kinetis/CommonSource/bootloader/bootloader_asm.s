;/******************************************************************************
;* 
;* Copyright (c) 2010 Freescale Semiconductor;
;* All Rights Reserved                       
;*
;*******************************************************************************
;*
;* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
;* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
;* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
;* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
;* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
;* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
;* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
;* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
;* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
;* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
;* THE POSSIBILITY OF SUCH DAMAGE.
;*
;***************************************************************************//*!
;*
;* @file      bootloader_asm.s
;*
;* @author    b01119
;* 
;* @version   0.0.24.0
;* 
;* @date      Sep-23-2012
;* 
;* @brief     Bootloader jump to application function for KEIL compiler
;*
;******************************************************************************/

	AREA    |.text|, CODE, READONLY

	EXPORT JumpToUserApplication
	
JumpToUserApplication
		msr msp, r0
		msr psp, r0        
		mov pc, r1

	END

