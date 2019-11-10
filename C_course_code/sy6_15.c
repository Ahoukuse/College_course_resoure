#include "TestModule/AhoTestModule.h"

short tmp_buff[5];


int is_prime(int number) {
    int i=2;
    for (; i <= sqrt((double)number); i++) {
        if (!(number%i))
        {
            return 0;
        }
        
    } 
    return 1;
}   

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
    int i; 
    i=3;
    custom_data(10,"%d\n",Ran_int(SEED,100,300));
     
    for (; i < 10000; i++)
    {
        if (is_prime(i) && is_prime(reverse_int(i)))
        {
            printf("%d ",i);
        }
        
    }
    
    DROP
    return 0;
}
