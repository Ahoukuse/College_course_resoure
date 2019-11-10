#include "TestModule/AhoTestModule.h"

double cos_c(double a,double b,double c){

    return (b*b-c*c+a*a)/(2*b*c);
}

double cos_to_sin(double cosc){

    return sqrt(1-cosc*cosc);
}

#define TS(a,b,c) (a*b)*cos_to_sin(cos_c(a,b,c))/2
#define LEN(a,b,c) a+b+c

int main(int argc, char const *argv[])
{
    INIT
    double a=0,b=0,c=0;
    TEST_SECTION_BEGIN(2)
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("C=%.2lf\n",LEN(a,b,c));
    printf("S=%.2lf\n",TS(a,b,c));
    TEST_SECTION_END
    DROP
    return 0;
}
