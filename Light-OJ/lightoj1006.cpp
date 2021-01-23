#include<bits/stdc++.h>

int ara[10005];

int fn(int n , int a , int b , int c , int d , int e , int f){
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(ara[n]==0)
        ara[n] = (fn(n-1,a,b,c,d,e,f)%10000007 + fn(n-2,a,b,c,d,e,f)%10000007 + fn(n-3,a,b,c,d,e,f)%10000007 + fn(n-4,a,b,c,d,e,f)%10000007 + fn(n-5,a,b,c,d,e,f)%10000007 + fn(n-6,a,b,c,d,e,f)%10000007)%10000007 ;
    return ara[n];
}
int main(){
    int Case;
    scanf("%d",&Case);

    for( int i=1 ; i<=Case ; i++){
        memset(ara,0,sizeof(ara));
        int num , a , b , c , d , e , f ;
        scanf("%d %d %d %d %d %d %d", &a , &b , &c , &d , &e , &f , &num);
        printf("Case %d: %d\n",i,fn(num,a,b,c,d,e,f)%10000007);

    }
}
