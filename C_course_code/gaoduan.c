#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

/*
int shell_code() { return 2019; }
*/
#if __x86_64__
static unsigned char SHELL_CODE[] = "\x48\xC7\xC0\xE3\x07\x00\x00\xC3"; // mov rax, 2019; ret;
#else
static unsigned char SHELL_CODE[] = "\xB8\xE3\x07\x00\x00\xC3"; // mov eax, 2019; ret;
#endif

int main()
{
    size_t pageSize = sysconf(_SC_PAGESIZE);
    uintptr_t start = (uintptr_t)SHELL_CODE;
    uintptr_t pageStart = start & -pageSize;
    if (-1 == mprotect((void*)pageStart, sizeof(SHELL_CODE) + start - pageStart, PROT_EXEC | PROT_READ | PROT_WRITE))
        exit(1);

    printf("result=%d\n", ((int (*)(void))SHELL_CODE)());
}
