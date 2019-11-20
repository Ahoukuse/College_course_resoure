#include <stdio.h>
#define N 5

struct student
{
    int    id;
    char   name[16];
    double math_grade;
    double english_grade;
    double ccourse_grade;
    double total_grade;

}students[5];


int main() {
    int i;
    double max_grade = -99999.0;
    double min_grade =  99999.0;
    for (i = 0; i < N; i++)
    {
        scanf("%d %s %lf %lf %lf",  &students[i].id,
                                     students[i].name,
                                    &students[i].math_grade,
                                    &students[i].english_grade,
                                    &students[i].ccourse_grade);

        students[i].total_grade  =   students[i].math_grade    +
                                     students[i].english_grade +
                                     students[i].ccourse_grade;

        max_grade = students[i].total_grade >= max_grade ? students[i].total_grade : max_grade;
        min_grade = students[i].total_grade <= min_grade ? students[i].total_grade : min_grade;        
    }
    puts("max:");
    for (i = 0; i < N; i++)
    {
        
        max_grade == students[i].total_grade ? printf("%03d %s %.1lf\n",
                                                                    students[i].id,
                                                                    students[i].name,
                                                                    students[i].total_grade):
        0;
    }

    puts("min:");
    for (i = 0; i < N; i++)
    {
       
        min_grade == students[i].total_grade ? printf("%03d %s %.1lf\n",
                                                                    students[i].id,
                                                                    students[i].name,
                                                                    students[i].total_grade):
        0;
    }
    return 0;
}