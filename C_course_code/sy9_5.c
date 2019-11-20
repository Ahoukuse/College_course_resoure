#include <stdio.h>

int main(){
    FILE *fp;
    int tmp_i;
    int pos_sum=0;
    int minus_sum=0;
    fp = fopen("number.txt","r");
    
    while (!feof(fp))
    {
        fscanf(fp,"%d",&tmp_i);
        tmp_i > 0 ? pos_sum   += tmp_i : 
        tmp_i < 0 ? minus_sum += tmp_i : 0;
    }
    
    tmp_i > 0 ? pos_sum   -= tmp_i : 
    tmp_i < 0 ? minus_sum -= tmp_i : 0;
    printf("\n%d\n%d",pos_sum,minus_sum);
    return 0;
}

//
// -2819