#include <stdio.h>

int print_sq(unsigned row,unsigned colum,char filler){
    
    int c = colum;
    int r = row - 2;
    int cc = colum - 2;
    while(c-- > 0){
        putchar(filler);
    }
    putchar('\n');
    while (r-- > 0)
    {
       putchar(filler);
       cc = colum-2;
       while (cc-- > 0 )
       {
           putchar(' ');
       }
       if (colum > 1){
        putchar(filler);
       }
       putchar('\n');

    }
    while (colum-- > 0 && row > 1)
    {
        putchar(filler);
    }
    putchar('\n');
    return 0;
}


int main(int argc, char const *argv[])
{
    unsigned r,c;
    char filler;
    scanf("%u %u %c",&r,&c,&filler);
    
    print_sq(r,c,filler);
    return 0;
}
