#include <stdio.h>
int is_number(char c){

    return c >= '0' && c <= '9' ? 1 : 0;
}


int main(int argc, char const *argv[])
{
    int i=0;
    char tmp[32] = {0x0};
    fgets(tmp,32,stdin);
    for (; tmp[i]; i++)
    {
        if (is_number(tmp[i]))
        {
           putchar(tmp[i]);
        }
        
    }
    putchar('\n');
    return 0;
}
