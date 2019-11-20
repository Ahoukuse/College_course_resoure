#include <stdio.h>
#include <string.h>
#include <math.h>

#define BYTE 8
#define BASE 16
int hex2dex(char *hex,unsigned int *ui){
    int i = 0;
    
    int len = strlen(hex)-1;
    *ui = 0;
    for (; len >= 0; len--,i++)
    {
        *ui += (hex[i] >= '9' ? 9 + hex[i]%BASE : hex[i]-'0') *(unsigned int)pow(BASE,len);
    }
        
    return 0;
}

int div2fchar(unsigned int target,char *c){
    int i;
    unsigned int mask = 0xFF;
    for (i = 0; i < 4; i++)
    {
        c[i] = (target & mask) >> BYTE*i;
        mask <<= BYTE;
    }
    
    return 4;
}


int main() {
    char str[32] = {0x0};
    char tmp_buff[5] = {0x0};
    unsigned int tmp_int;
    scanf("%s",str);
    hex2dex(str,&tmp_int);
    div2fchar(tmp_int,tmp_buff);
    //printf("%s\n",str);
    printf("%s\n",tmp_buff);
    return 0;
    // 1145258561
}
