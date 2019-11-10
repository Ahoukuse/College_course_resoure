/*----------------------------------------------------------------
|                                                                 |
|       https://github.com/Ahoukuse/College_course_resoure        |                                          |
|                                                                 |
|----------------------------------------------------------------*/


/*

    本模块在
          OS: Ubuntu19.10
          Arc: x64
          gcc: 8.3.0
    编译通过

    本模块在
         OS: Windows10 
         Arc: x64
         Env: Visual Studio 2019
    编译通过

    
    >>>>>>>> 但本模块并不兼容目前也不打算兼容或支持Windows <<<<<<<<<<
 
*/


/*

    测试模块 
    待完成
    极不稳定
            ---fengg
*/

//我全都要.gif

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




/*

    若在非"Debug"预编译宏的修饰下，将所以Debug宏
    定义为空。
    虽然不专业，但方便啊！！！

*/

#ifndef Debug
#define CURRENT_LOOP 
#define INIT 
#define DROP 
#define logg(x,...)
#define loggerr(x,...)
#define loggcyan(x,...)
#define TEST_SECTION_BEGIN(x)
#define custom_data(x,format,...)
#define TEST_SECTION_END
#endif 

///
///随机字符生产器  >>>弃用<<<
///
int Gen_char(int len,int times);

///
///随机数生产器    >>>弃用<<<
///
int Gen_int(int base,int len,int row,int column);

int Gen_data();
int Ran_int(unsigned seed,int base,unsigned len);
char* Ran_char(unsigned seed,int len);
#define SHOWERR   0x01  //显示错误
#define SHOWCURR  0x10  //显示正确


//若在"Debug"预编译宏修饰下,定义所以Debug宏

#ifdef Debug

/// >>>>>>>>>>>>>>弃用<<<<<<<<<<<<<<<
/// 以下两个宏定义输入输出文件。用于测试数据输入
/// 输出.       
/// >>>>>>>>>>>>>>弃用<<<<<<<<<<<<<<<
#define OUT_DATA_FILE_NAME "out.data"
#define IN_DATA_FILE_NAME  "in.data"

#define CURRENT_LOOP ikl+1

FILE *out_set;
FILE *in_set;

///
/// 初始化测试环境
///
#define INIT out_set=fopen(OUT_DATA_FILE_NAME,"r+");\
             in_set=fopen(IN_DATA_FILE_NAME,"r+");  \


#define DROP fclose(out_set);\
             fclose(in_set);

#define custom_data(x,format,...) for(size_t SEED = 0; SEED < (x); SEED++){fprintf(in_set,format,##__VA_ARGS__);}fseek(in_set,0,0);    
                                                               

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