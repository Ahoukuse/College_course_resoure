#include <stdio.h>
#include <string.h>
struct contact{
    int id;
    char name[32];
    char gender[8];
    char phone_number[32];
}tmp_contact;

int main(){
    FILE *fp;
    int i;
    struct contact  guys[3] ={
        {1,"小洋","男","13811223344"},
        {2,"小明","女","13312512433"},
        {3,"小马","男","15911332255"}
    };
    scanf("%d %s %s %s",
                       &tmp_contact.id,
                        tmp_contact.name,
                        tmp_contact.gender,
                        tmp_contact.phone_number
                            );
    if((fp=fopen("address.txt","wb"))==NULL){
        return 1;
    }

    for ( i = 0; i < 3; i++)
    {
        fwrite(&guys[i],sizeof(guys[i]),1,fp);
    }
    
    fwrite(&tmp_contact,sizeof(tmp_contact),1,fp);   
    fclose(fp);
    if((fp=fopen("address.txt","r"))==NULL){
        return 2;
    }
    fseek(fp,0,0);
    for (i = 0;i<4; i++)
    {
        fread(&tmp_contact,sizeof(tmp_contact),1,fp);
                            
        printf("%d %s %s %s\n",
                        tmp_contact.id,
                        tmp_contact.name,
                        tmp_contact.gender,
                        tmp_contact.phone_number
                            );

    }
    fclose(fp);
    return 0;
}