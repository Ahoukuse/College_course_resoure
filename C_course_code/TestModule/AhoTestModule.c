#include <stdio.h>
#include <time.h>
#include "AhoTestModule.h"

int Gen_char(int len,int times){
    FILE *fp;
    fp = fopen("in.data","w+");
    char tmp[1000]={0x0};
    time_t t;
    for (size_t i = 0; i < times; i++)
    {
        srand((unsigned)time(&t)+i);
        for (size_t i = 0; i < len; i++)
        {
            tmp[i] = 'a'+rand()%25;
        }
        fprintf(fp,"%s\n",tmp);
    }
    
    fclose(fp);
    return 0;
}

int Gen_int(int base,int len,int times){
    FILE *fp;
    int tmp;
    fp = fopen("in.data","w+");
    time_t t;
    for (size_t i = 0; i < times; i++)
    {
        srand((unsigned)time(&t)+i);
        tmp = rand()%len + base;
        fprintf(fp,"%d\n",tmp);
    }
    
    fclose(fp);
    return 0;
}