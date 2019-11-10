#include "TestModule/AhoTestModule.h"

int diff(char *str1,char *str2){
    int i=0;
    while(str1[i] != '\0'){
        str1[i] = str1[i] == '\n' ? '\0':str1[i];i++;
    }
    i = 0;
    while(str2[i] != '\0'){
        str2[i] = str2[i] == '\n' ? '\0':str2[i];i++;
    }
    for(i = 0;str1[i]==str2[i] && ( str1[i] != '\0' && str2[i] != '\0');i++);
    //printf("%d   %d\n",str1[i],str2[i]);
    return abs(str1[i] - str2[i]);
}

int main(int argc, char const *argv[])
{
    INIT
    char tmp[64] = {0x0},tmp2[64] = {0x0};
    TEST_SECTION_BEGIN(3)

    fgets(tmp,sizeof(tmp),stdin);
    fgets(tmp2,sizeof(tmp),stdin);
    printf("%d\n",diff(tmp,tmp2));
    TEST_SECTION_END
    DROP
    return 0;
}
