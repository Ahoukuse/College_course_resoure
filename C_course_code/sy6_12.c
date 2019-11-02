#include <stdio.h>




int main(){
    int i,t;
    int tmp[10] = {0x0,0x0,999999,-999999};
    int index4min=2,index4max=3;

    for ( i = 0; i < 10; i++)
    {
        scanf("%d",&tmp[i]);
        tmp[i] > tmp[index4max] ? index4max = i : 0;
        tmp[i] < tmp[index4min] ? index4min = i : 0;
    }

    t = tmp[index4min];
    tmp[index4min] = tmp[index4max];
    tmp[index4max] = t;

    for ( i = 0; i < 10; i++)
    {
        printf("%d ",tmp[i]);
    }
    return 0;
}