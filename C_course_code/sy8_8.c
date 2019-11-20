#include <stdio.h>
#include <math.h>

#define N 2

struct vector2{

    double x;
    double y;

};

typedef struct vector2 vector2;

vector2 vector2_center(vector2 v1,vector2 v2){
    vector2 vc;
    vc.x = (v1.x+v2.x)/2;
    vc.y = (v1.y+v2.y)/2;
    return vc;
}

double distant(vector2 v1,vector2 v2){
    
    return sqrt(pow(v1.x-v2.x,2)+pow(v1.y-v2.y,2));

}

int main() {
    int i;
    vector2 v[N];
    vector2 center;
    for (i = 0; i < N; i++)
    {
        scanf("%lf %lf",&v[i].x,&v[i].y);
    }
    center = vector2_center(v[0],v[1]);
    printf("%.3lf,%.3lf\n",center.x,center.y);
    printf("%.3lf",distant(v[0],v[1]));
    return 0;
}