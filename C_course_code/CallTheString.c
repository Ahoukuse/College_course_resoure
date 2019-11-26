#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#define  NOP 0x90 
#define  M_SIZE 128

static char justAJust[]    = "Hello world!";

//这是个我自己构造的字符串，其功能是同justAFun一样的
static char justAString[M_SIZE] = {0x55,0x48,0x89,0xe5,
                                   0x48,0x83,0xec,0x10,
                                   0x48,0x89,0x7d,0xf8,
                                   0x48,0x8b,0x45,0xf8,
                                   0x48,0x89,0xc7,0xe8,
                                   0xa8,0xdc,0xe7,0xff,
                                   0x90,0xc9,0xc3,0x90};

void justAFun(char *justAJust){
    puts(justAJust);
}


int main(int args,char *argv[]){
    int i = 0;
    char *justACharPtr       = NULL;
    void (*justAPtr)(char *) = NULL;
    justACharPtr             = (char *) justAFun;
    

    memset(&justAString[strlen(justAString)],NOP,M_SIZE-strlen(justAString));

    
    //mprotect(justAString,24,PROT_EXEC | PROT_READ);  //尝试去赋予justString可执行属性，但不管用
    puts("justAFun函数16进制表示： ");
    do 
    {

        printf("%#x",justACharPtr[i] & 0xFF);        //显示justAFun的'内容'

    } while((justACharPtr[i++] & 0xFF) != 0xc3 && putchar(','));
    putchar('\n'); 

    justAFun(justAJust);                             //非常普通的调用justAFun

    justAPtr = justAFun;                             //使用函数指针调用justAFun
    justAPtr(justAJust); 
    justAPtr = mmap(NULL,M_SIZE,PROT_EXEC | PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,0,0);
    if (justAPtr == NULL || justAPtr == MAP_FAILED)
    {
        puts("mmap失败");
        return -1;
    }
    
    memcpy(justAPtr,justAString,M_SIZE);
    justAPtr(justAJust);   



    return 0;

}