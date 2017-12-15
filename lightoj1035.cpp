#include<bits/stdc++.h>

using namespace std;
int primes[100];
int flage[100];
void seive(){
    for( int i=0 ; i<100 ; i++)
        flage[i]=1;

    for( int i=2 ; i*i<100 ; i++)
        if(flage[i])
            for( int j=i ; i*j<100 ; j++)
                flage[i*j] = 0;

    int k=0;
    for( int i=2 ; i<100 ; i++)
        if(flage[i])
            primes[k++] = i;
}

int main(){
    seive();

    int t;
    scanf("%d",&t);

    for( int i=1 ; i<=t ; i++){
        int N;
        int ara[101];
        for( int j=0 ; j<101 ; j++)
            ara[j] = 0;
        scanf("%d",&N);
        int num , index = 0;
        for( int j=N ; j>1 ; j--){
            num = j , index = 0 ;
            while(num!=1){
                if(num%primes[index]==0){
                    ara[index]++;
                    num/=primes[index];
                }
                else
                    index++;
            }
        }
        int j;
        for( j=0 ; j<100 ; j++)
            if(ara[j]>0){
                printf("Case %d: %d = %d (%d)",i,N,primes[j] , ara[j]);
                break;
            }
        for( int m=j+1 ; m<100 ; m++)
            if(ara[m]>0)
                printf(" * %d (%d)",primes[m] , ara[m]);
        printf("\n");
    }
    return 0;
}
