

#include "TestModule/AhoTestModule.h"

#define MIN_INT -999999

int main(int argc, char const *argv[]) {
    int tmp_int= 0x0, max_int, index;
    INIT
    custom_data(20,"%d %d %d\n",
                Ran_int(SEED,-50,100),
                Ran_int(SEED*5,0,100),
                Ran_int(SEED*7,0,100));
    TEST_SECTION_BEGIN(20)


    max_int = MIN_INT;
    for (index = 0; index < 3; index++) {
        scanf("%d",&tmp_int);
        max_int = max_int < tmp_int ? tmp_int : max_int;
    }  
    printf("%d\n",max_int);



    TEST_SECTION_END
    DROP
    return 0;
}
