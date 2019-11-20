#include <stdio.h>
#include <string.h>
int sort(char (*tmp)[40]){
    int i,j;
    char t[40] = {0x0};
    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
           if(strcmp(tmp[j],tmp[j+1]) > 0){
               memcpy(t,tmp[j+1],40);
               memcpy(tmp[j+1],tmp[j],40);
               memcpy(tmp[j],t,40);
           }
        }
    }
    return 0;
}



int main() {
    int i,j;
    char cha[10][40]  = {{0x0}};
    for ( i = 0; i < 10; i++)
    {
        j = 0;
        //fgets(cha[i],40,stdin);
        while ((cha[i][j] = getchar()) != '\n' && j < 40)
        {
            if (cha[i][j] == EOF)
            {
                cha[i][j] = '\n';
                break;
            }
            
            j++;
        }
        //printf("结束符Index: %d\n",cha[i][j]);
    }
    //for ( i = 0; i < 10; i++)
    //    printf("第%d行: %s\n",i,cha[i]);
    
    sort(cha);
    //printf("第9行20个: %d %c 第9行21个: %d %c\n",cha[8][19],cha[8][19],cha[8][20],cha[8][20]);
    for ( i = 0; i < 10; i++)
    {
        printf("%s",cha[i]);
    }
    return 0;
}