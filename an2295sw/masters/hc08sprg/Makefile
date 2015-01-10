#**********************************************************************
# HEADER_START
#
#      Name:           MAKEFILE
#      Project:        Developper's HC08 Bootloader Master
#      Description:    Makefile for Linux
#      Platform:       Linux
#      Revision:       1.0
#      Date:           Apr 8 2002
#      Author:         Michal Hanak
#      Company:        Motorola SPS
#      Security:       General Business
#
# ===================================================================
# Copyright (c):      MOTOROLA Inc., 2001, All rights reserved.
#
# ===================================================================
# THIS SOFTWARE IS PROVIDED BY MOTOROLA "AS IS" AND ANY
# EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL MOTOROLA OR
# ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
# ===================================================================
#
# HEADER_END
#

# Makefile for linux version
#

CC = gcc
#CC = ppc_8xx-gcc 

CFLAGS = -W -O2 -g 
#CFLAGS = -W -O2 -g -D_DEBUG

TARG = hc08sprg
OBJS = main.o prog.o s19.o serial.o seriallinux.o

all: hc08sprg

hc08sprg: $(OBJS)
	$(CC) -o $(TARG) $(OBJS)

main.o: main.c hc08sprg.h sysdeplinux.h serial.h
	$(CC) $(CFLAGS) -c -o $*.o $<

prog.o: prog.c hc08sprg.h sysdeplinux.h serial.h
	$(CC) $(CFLAGS) -c -o $*.o $<

s19.o: s19.c hc08sprg.h sysdeplinux.h
	$(CC) $(CFLAGS) -c -o $*.o $<

serial.o: serial.c sysdeplinux.h serial.h
	$(CC) $(CFLAGS) -c -o $*.o $<

seriallinux.o: seriallinux.c sysdeplinux.h serial.h
	$(CC) $(CFLAGS) -c -o $*.o $<

*.c *.h: Makefile
	@touch $@

clean:
	rm -f $(OBJS) $(TARG)

install: hc08sprg
	cp $(TARG) /pub
