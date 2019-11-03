/*

    测试模块 

*/



#ifdef Debug
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


FILE *out_set;
FILE *in_set;


#define INIT out_set=fopen("out.data","w+");\
             in_set=fopen("in.data","w+");
#define DROP fclose(out_set);\
             fclose(in_set);

int Gen_char(int len,int times);
int Gen_int(int base,int len,int times);

#define log(format,...) fprintf(stdout,format,__VA_ARGS__);

#define printf(format,...) fprintf(out_set,format,__VA_ARGS__);

#define scanf(format,...)  fscanf(in_set,format,__VA_ARGS__);

#define TEST_SECTION_BEGIN(times) for(size_t i=0;i<(times); i++){

#define TEST_SECTION_END }

#endif // Debug