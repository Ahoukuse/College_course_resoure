#include <stdio.h>
#include <string.h>

int is_number(char str){
    return str >= '0' && str <= '9'? 1 : 0;
}

int getIntFromStr(char *str,int *int_arr){
    *int_arr = str[0]-'0';
    int i=1;

    while(is_number(str[i])){
        *int_arr = *int_arr*10 + str[i++]-'0';
    }
    return i;
}

int divStr2Int(char *str_buff,int *int_buff){
    int i,j;
    for(i=0,j=0;str_buff[i] != 0x0;i++){
        if(is_number(str_buff[i])){
          i += getIntFromStr(&str_buff[i],&int_buff[j++]);
        }
    }

    return j;
}

int print_int_array(int *int_arr,int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",int_arr[i]);
    }
    putchar('\n');
    return 0;
}


int main(){
    int  int_buff[128];
    char tmp_buff[128];
    int size;
    scanf("%s",tmp_buff);

    size = divStr2Int(tmp_buff,int_buff);

    print_int_array(int_buff,size);
    printf("%d",size);
    return 0;
}