#include<cstdio>

int main(){

    int T;
    scanf("%d",&T);

    for( int Case=1 ; Case<=T ; Case++){
        int N , x , sum=0;
        scanf("\n%d",&N);
        while(N--){
            scanf("%d",&x);
            if(x>0)
                sum+=x;
        }
        printf("Case %d: %d\n",Case,sum);
    }
}
