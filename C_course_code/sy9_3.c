#include <stdio.h>
#include <string.h>
#define N 5

struct student{

    char id[64];
    char name[32];
    float grade_one;
    float grade_two;
    float grade_three;
    float average;

}tmp_student ;

int main(){
    
    FILE *fp;
    int i;
    fp = fopen("stud","wb");
    for ( i = 0; i < N; i++)
    {
    

        scanf("%s %s %f %f %f",  tmp_student.id,
                                    tmp_student.name,
                                &tmp_student.grade_one,
                                &tmp_student.grade_two,
                                &tmp_student.grade_three
                                                            );

        tmp_student.average     =  (tmp_student.grade_one    +
                                    tmp_student.grade_two    +
                                    tmp_student.grade_three) / 3;     

        
        fwrite(&tmp_student,sizeof(tmp_student),1,fp);
    }
    fclose(fp);
    fp = fopen("stud","rb");
    while(!feof(fp))
    {
        fread(&tmp_student,sizeof(tmp_student),1,fp);
        printf("%s %s %f %f %f",    tmp_student.id,
                                    tmp_student.name,
                                    tmp_student.grade_one,
                                    tmp_student.grade_two,
                                    tmp_student.grade_three);
    }
    
    fclose(fp);   
    
                                                                         
    return 0;
}