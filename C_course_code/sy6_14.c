#include "TestModule/AhoTestModule.h"

int sort(char *str){
    int i,j,len;
    char tmp;
    len = strlen(str)-1;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            if( str[j+1] < str[j] ){
                
                tmp = str[j+1];
                str[j+1] = str[j];
                str[j] = tmp;

            }
        }
    }


    return 0;
}


int main(int argc, char const *argv[])
{
    INIT;
    char str[32]={0x0};
    custom_data(10,"%s\n",Ran_char(SEED,9));
    TEST_SECTION_BEGIN(10)

    scanf("%s",str);
    if(strlen(str) > 10){
        printf("String too long\n");
        return 0;
    }
    sort(str);
    printf("%s\n",str);
    TEST_SECTION_END
    return 0;
}
