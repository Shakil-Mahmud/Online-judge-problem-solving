#include<cstdio>
#include<cmath>
#define pi 2 * acos (0.0)

int main(){

    int t;
    double r , circle = 0.0 , square = 0.0;

    scanf("%d",&t);

    for( int i=1 ; i<=t ; i++){
        scanf("%lf",&r);
        circle = r*r*pi;
        square = (2.0*r)*(2.0*r);
        printf("Case %d: %0.2lf\n",i,square-circle);
    }
}
