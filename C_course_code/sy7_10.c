
#include <stdio.h>
#include <string.h>

int delSpechar(char *tmp_buff,char c){
    int i;
    for (i = 0; i < strlen(tmp_buff); i++)
    {
        tmp_buff[i] == c ? memmove(&tmp_buff[i],&tmp_buff[i+1],strlen(&tmp_buff[i+1])) : NULL;
    }

    return 0;
}


int main() {
    char tmp_buff[128] = {0x0};
    char c;
    fgets(tmp_buff,128,stdin);
    scanf("%c",&c);
    
    delSpechar(tmp_buff,c);

    puts(tmp_buff);
    return 0;
}