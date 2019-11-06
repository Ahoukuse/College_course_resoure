//
// Create By fengg
// 
#include <stdio.h>
#include <math.h>
#include "TestModule/AhoTestModule.h"


int main(int argc, char const *argv[])
{
    INIT
    int num,i,flag=1;
    Gen_int(100,100,20,1);
    TEST_SECTION_BEGIN(20)
    scanf("%d",&num);
    if (num < 2)
    {
        printf("No\n");
        return 0;
    }
    
    for (i = 2,flag=1; i <= sqrt((double)num); i++)
    {
        if(!(num%i)){
            flag = 0;
            break;
        }
    }
    //loggerr("%d\n",num);
    printf("%s",flag?"Yes\n":"No\n");
    TEST_SECTION_END

    

    return 0;
}
