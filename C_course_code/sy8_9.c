#include <stdio.h>
#include <math.h>

#define N 2

struct vector2{

    double x;
    double y;

};

typedef struct vector2 vector2;

double distant(vector2 v1,vector2 v2){
    
    return sqrt(pow(v1.x-v2.x,2)+pow(v1.y-v2.y,2));

}

int main() {
    int i;
    vector2 v[N];
    for (i = 0; i < N; i++)
    {
        scanf("%lf %lf",&v[i].x,&v[i].y);
    }
    printf("%.2lf",distant(v[0],v[1]));
    return 0;
}