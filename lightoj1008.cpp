#include<cstdio>
#include<cmath>
int main(){

    int T;
    scanf("%d",&T);

    for( int Case=1 ; Case<=T ; Case++){
        long long int S;
        scanf("%lld",&S);

        double sq = sqrt(S);
        int Sq = ceil(sq);
        if(ceil(sq)-floor(sq)==0)
            Sq = sq;
        if(Sq%2==0)
            Sq++;

        if(S==1)
            printf("Case %d: 1 1\n",Case);
        else{
            for( long long int i=Sq ; i<=Sq ; i+=2){
                if(i*i>=S){

                    long long int si = (i-2)*(i-2);
                    if( S <= (si+i-1) ){
                        printf("Case %d: %d %d\n",Case,S-si,i-1);
                        break;
                    }

                    si+= (i-1);
                    if( S <= (si+i-2) ){
                        printf("Case %d: %d %d\n",Case,i-1,(si+i-1-S));
                        break;
                    }

                    si += i-2;
                    if( S<= (si+i) ){
                        printf("Case %d: %d %d\n",Case,i,(S-si));
                        break;
                    }

                    si+=i;
                    if( S <= i*i ){
                        printf("Case %d: %d %d\n",Case,(i*i-S+1),i);
                        break;
                    }
                }
            }
        }
    }
}
