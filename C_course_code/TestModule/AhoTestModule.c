#include "AhoTestModule.h"
#ifdef Debug
static char temp[1000] = {0x0};
#endif // Debug
int Gen_char(int len,int times){
#ifdef Debug

    FILE *fp;
    fp = fopen(IN_DATA_FILE_NAME,"w+");
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

#endif // Debug
    return 0;
}

int Gen_int(int base,int len,int row,int column){
#ifdef Debug
    FILE *fp;
    int tmp;
    fp = fopen(IN_DATA_FILE_NAME,"w+");
    time_t t;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
           srand((unsigned)time(&t)+i*12+j*6);
           tmp = rand()%len + base;
           fprintf(fp,"%d ",tmp);
        }  
        fprintf(fp,"\n");
    }
    
    fclose(fp);
#endif
    return 0;
}

char* Ran_char(unsigned seed,int len){
#ifdef Debug
    srand((unsigned)time(NULL)+seed);
    for (size_t i = 0; i < 1000; i++)
    {
        temp[i] = '\0';
    }
    for (size_t i = 0; i < len; i++)
    {
        temp[i] = 'a'+rand()%25;
    }
    return temp;
#else 
    return NULL;
#endif
}

int Ran_int(unsigned seed,int base,unsigned len){
    srand((unsigned)time(NULL)+seed);
    return rand()%len + base;
}

void Static_analyze(char *checkfile,int num,int flag){
#ifdef Debug
    
   
    char tmp[300]     = {0x0};
    char tbcheck[300] = {0x0};
    FILE *check,*out;
    check = fopen(checkfile,"r");
    out   = fopen(OUT_DATA_FILE_NAME,"r");

    logg("\n数据测试开始\n\n");

    for (size_t i = 0; i < num; i++)
    {
        
        int t=0;
        fgets(tmp,300,check);
        fgets(tbcheck,300,out);

        while(tmp[t]!='\0'){
            tmp[t] = tmp[t] == '\n' ? ' ' : tmp[t];
            t++;
        }
        t = 0;
        while(tbcheck[t]!='\0'){
            tbcheck[t] = tbcheck[t] == '\n' ? ' ' : tbcheck[t];
            t++;
        }
        
        switch (flag)
        {
        case 0x01:
            
            if(strcmp(tmp,tbcheck)){
                logg("-----数据[%03lu]-----\n",i+1);
                logg("期望输出 %s\n",tmp);
                loggerr("实际输出 %s错误!\n",tbcheck);
            }
            break;
        case 0x10:
            
            if(!strcmp(tmp,tbcheck)){
                logg("-----数据[%03lu]-----\n",i+1);
                logg("期望输出 %s\n",tmp);
                loggcyan("实际输出 %s正确!\n",tbcheck);
            }
            break;
        case 0x11:
            logg("-----数据[%03lu]-----\n",i+1);
            if(!strcmp(tmp,tbcheck)){
                logg("期望输出 %s\n",tmp);
                loggcyan("实际输出 %s正确!\n",tbcheck);
            } else {
                logg("期望输出 %s\n",tmp);
                loggerr("实际输出 %s错误!\n",tbcheck);
            }
            break;
        default:
            break;
        }
        
    }
#endif // DEBUG  
}
