#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define  NOP 0x90 
#define  M_SIZE 128

static char justAJust[]    = "Hello world!";

//这是个我自己构造的字符串，其功能是同justAFun一样的
static char justAString[M_SIZE] = {0x55,                            //push   %rbp
                                   0x48,0x89,0xe5,                  //mov    %rsp,%rbp
                                   0x48,0x83,0xec,0x10,             //sub    $0x10,%rsp
                                   0x48,0x89,0x7d,0xf8,             //mov    %rdi,-0x8(%rbp)
                                   0x48,0x8b,0x45,0xf8,             //mov    -0x8(%rbp),%rax
                                   0x48,0x89,0xc7,                  //mov    %rax,%rdi
                                   0xe8,0xe8,0xcf,0xff,0xff,        //callq  xxxx <puts@plt>
                                   0x90,                            //nop
                                   0xc9,                            //leaveq
                                   0xc3,                            //retq
                                   0x90                             //nop
                                   };

void justAFun(char *justAJust){
    puts(justAJust);
}


int main(int args,char *argv[]){
    int i = 0;
    size_t pageSize = sysconf(_SC_PAGE_SIZE);       //获得内存页大小
    char *justACharPtr       = NULL;
    void (*justAPtr)(char *) = NULL;
    justACharPtr             = (char *) justAFun;

    //计算页起始地址
    uintptr_t start = (uintptr_t) justAString;
    uintptr_t pageStart = start & -pageSize;
    memset(&justAString[strlen(justAString)],NOP,M_SIZE-strlen(justAString));

    if (mprotect((void *)pageStart,M_SIZE+start-pageStart,PROT_EXEC | PROT_READ | PROT_WRITE) == -1)
    {
       return -1;
    }
    
    puts("justAFun函数16进制表示： ");
    do 
    {

        printf("%#x",justACharPtr[i] & 0xFF);        //显示justAFun的'内容'

    } while((justACharPtr[i++] & 0xFF) != 0xc3 && putchar(','));
    putchar('\n'); 

    justAFun(justAJust);                             //非常普通的调用justAFun

    justAPtr = justAFun;                             //使用函数指针调用justAFun
    justAPtr(justAJust); 
    
    justAPtr = (void (*)(char*))justAString;         //调用一个字符串justAString
    justAPtr(justAJust);   



    return 0;

}