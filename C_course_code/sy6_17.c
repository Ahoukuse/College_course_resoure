#include "TestModule/AhoTestModule.h"

#define BASE 8

short tmp_buff[32];

int reverse_arralize_int(int number){
    int i=0;
    memset(tmp_buff,0x0,sizeof(tmp_buff));
    for (;number; number/=10,i++)
    {
        tmp_buff[i] = number%10;
    }
    return i-1;
}

int reverse_int(int number){
    int tmp=0,i=0,len;
    len = reverse_arralize_int(number);
    for (; len >= 0; len--)
    {
        tmp += tmp_buff[i++]*(int)pow(10,(double)len);
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
    printf("%d\n",reverse_int(d));
    TEST_SECTION_END

    DROP
    return 0;
}
