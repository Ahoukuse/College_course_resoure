#include<stdio.h>
#include <string.h>
#include <math.h>

int strCrossCat(char *b,char *a){
    int len_a ,
        len_b ,
        j = 0,
        i;
    i = 0;
    while(b[i] != '\0'){
        b[i] = b[i] == '\n' ? '\0':b[i];i++;
    }
    i = 0;
    while(a[i] != '\0'){
        a[i] = a[i] == '\n' ? '\0':a[i];i++;
    }
    len_a = strlen(a);
    len_b = strlen(b);
    for (i = 1; i < len_b; i++)
    {
        b[i+len_a+len_b] = b[i];
        b[i] = '\0';
    }
    
    for ( i = 1,j = 0; i <= 2*len_a && a[j]!=0x0 && b[len_a+len_b+j+1]!=0x0; j++)
    {

        b[i++] = a[j];
        b[i] = b[len_a+len_b+j+1];
        i++;
    }

    strcat(&b[j+1],a[j]==0x0?&b[len_a+len_b+j+1]:&a[j]);

    return 0;
}

int main(void)
{
    char tmp[256] = {0x0};
    char tmp2[256] = {0x0};

    fgets(tmp,128,stdin);
    fgets(tmp2,128,stdin);

    strCrossCat(tmp2,tmp);
    
    puts(tmp2);

	return 0;
}
