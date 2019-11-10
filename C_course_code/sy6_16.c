#include "TestModule/AhoTestModule.h"

#define BASE 8

short tmp_buff[32];

int arralize_oct(int number){
    int i=0;
    memset(tmp_buff,0x0,sizeof(tmp_buff));
    for (;number; number/=BASE,i++)
    {
        tmp_buff[i] = number%BASE;
    }
    return i-1;
}

int Dec2Oct(int number){
    int tmp=0,len=0;
    len = arralize_oct(number);
    for (; len >= 0;len--)
    {
        tmp += tmp_buff[len]*(int)pow(10,(double)(len));
    }
    return tmp;
}


int main(int argc, char const *argv[])
{
    INIT
    int d=0;
    custom_data(10,"%d\n",Ran_int(SEED,0,50));
    TEST_SECTION_BEGIN(10)
    
    scanf("%d",&d);
    printf("%d\n",Dec2Oct(d));
    TEST_SECTION_END

    DROP
    return 0;
}
