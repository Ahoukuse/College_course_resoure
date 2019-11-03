/*

    测试模块 

*/

#ifndef _STDIO_H
#include <stdio.h>
#endif // !_STDIO_H
#ifndef _STDARG_H
#include <stdarg.h>
#endif // !_STDARG_H
#ifndef _MATH_H
#include <math.h>
#endif // !MATH_H
#ifndef _STDLIB_H
#include <stdlib.h>
#endif // !_STDLIB_H
#ifndef _TIME_H
#include <time.h>
#endif // !_TIME_H
#ifndef _STRING_H
#include <string.h>
#endif // !_STRING_H






#if defined Localhost && !defined Debug
#define CURRENT_LOOP 
#define INIT 
#define DROP 
#define logg(x,...)
#define loggerr(x,...)
#define loggcyan(x,...)
#define TEST_SECTION_BEGIN(x)
#define TEST_SECTION_END
#endif // Localhost

int Gen_char(int len,int times);
int Gen_int(int base,int len,int row,int column);

#define SHOWERR   0x01
#define SHOWCURR  0x10

#ifdef Debug

#define OUT_DATA_FILE_NAME "out.data"
#define IN_DATA_FILE_NAME  "in.data"

#define CURRENT_LOOP ikl+1

FILE *out_set;
FILE *in_set;


#define INIT out_set=fopen(OUT_DATA_FILE_NAME,"w");\
             in_set=fopen(IN_DATA_FILE_NAME,"r");
#define DROP fclose(out_set);\
             fclose(in_set);



#define loggl(format,...) fprintf(stdout,"[第%03d行] ",__LINE__);fprintf(stdout,format,##__VA_ARGS__)

#define logg(format,...)  fprintf(stdout,format,##__VA_ARGS__)

#define loggerr(format,...) fprintf(stdout,"\e[1;31m" format "\033[0m\n",##__VA_ARGS__)

#define loggcyan(format,...) fprintf(stdout,"\e[1;36m" format "\033[0m\n",##__VA_ARGS__)

#define printf(format,...) fprintf(out_set,format,##__VA_ARGS__);

#define scanf(format,...)  fscanf(in_set,format,##__VA_ARGS__);

#define TEST_SECTION_BEGIN(times) loggl("---测试起始----\n");for(size_t ikl=0;ikl<(times); ikl++){

#define TEST_SECTION_END }loggl("---测试结束----\n");

void Static_analyze(char *checkfile,int num,int flag);

#endif // Debug