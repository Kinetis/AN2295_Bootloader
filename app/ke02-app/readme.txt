Kinetis KE02 Sample Code

1) Contents

This package contains a number of bare-metal example projects for the Kinetis 
E series processors (including header files and initialization code).

Currently supported hardware platforms are:
- FRDM-KE02Z

2) Directory Structure

ke02_sc\
|--build\
|--src\

build\ - All development toolchain specific files are located in this
         subdirectory.

src\   - All source files are arranged in folders inside this 
         directory.

The src\ tree is broken up as follows:

src\common\    - Common utilities such as printf and stdlib are 
                 provided in this directory
src\cpu\       - CPU specific initialization and header files here
src\drivers\   - Drivers for some of the various peripherals are  
                 provided here.
src\platforms\ - Each supported platform has a header file that defines
                 board specific information, such as the input clock
                 frequency used for that board.
src\projects\  - This directory holds all the individual example
                 project source code

3) Toolchain Support

Currently the IAR v6.60, CW10.4, and KEIL uVision v4.72 toolchains are supported.



4) Creating new projects

IAR Bare-metal projects
--------------------------

The ke02-sc\build\iar\make_new_project.exe files can be used to clone the platinum project.
The script will prompt you for a name to use for the new project, then creates copies of all needed 
files and folders.


KEIL uVision Bare-metal projects
----------------------------------
The ke02-sc\build\keil\make_new_project-sc_Keil.exe can be used to clone the platinum 
project.  The script will prompt you for a name to use for the new project, then creates copies of 
all needed files and folders.  

Codewarrior Bare-metal projects
-----------------------------------
The ke02-sc\build\cw\make_new_cw_project.exe file can be used to clone the platinum project.
The script will prompt you for a name to use for the new project, then creates copies of all needed
compiler specific files and folders.  The main source file and ke02-sc\src\cw\{proj name} 
files will need to be manually created.  

5) Revision History

Date:  7/18/13
Current revision:  Rev1


