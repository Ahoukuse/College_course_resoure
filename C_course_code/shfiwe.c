#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#ifdef __x86_64__
//x64
char code[]={
       0x55, //push %rbp
       0x48,0x89,0xe5, //mov %rsp,%rbp
       0x48,0x83,0xec,0x10, //sub  $0x10,%rsp
       0x48,0xb8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //movabs $puts,%rax
       0xff,0xd0, //callq  *%rax
       0xc9,0xc3 //leaveq retq
};
int code_size = sizeof(code);
int puts_off = 10;

#elif __i386__
//x86
char code[]={
    0x55,   //push %ebp
    0x89,0xe5, //mov %esp,%ebp
    0x83,0xec,0x18, //sub $0x18,%esp
    0x8b,0x45,0x08, //mov 0x8(%ebp),%eax
    0x89,0x04,0x24, //mov %eax,(%esp)
    0xb8,0x0,0x0,0x0,0x0, //mov $puts,%eax
    0xff,0xd0, //call *%eax
    0xc9,0xc3 //leave ret
};

int code_size = sizeof(code);
int puts_off = 13;
#endif

void (*method)(char *) = NULL;



int main(int args,char *argv[]){

    *(void**)(code+puts_off) = (void*)puts;

    method = mmap(NULL,code_size,PROT_READ | PROT_WRITE | PROT_EXEC,MAP_PRIVATE | MAP_ANONYMOUS,0,0);

    if(method == NULL || method == MAP_FAILED){
        perror("mmap code mem fail");
        return -1;
    }

    memcpy(method,code,code_size);

    method("hello world");

    return 0;

}