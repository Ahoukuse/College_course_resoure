#include "TestModule/AhoTestModule.h"

int main(int argc, char const *argv[])
{
    INIT
    int mat[3][3],i,j;
    Gen_int(0,10,9,3);
    TEST_SECTION_BEGIN(3)
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&mat[i][j]);
        }
        
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ",mat[j][i]);
        }
        printf("\n");
    }
    TEST_SECTION_END
    DROP
    return 0;
}
