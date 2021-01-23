#include<cstdio>

int sum;
int ara[100005];
int tree[4*100005];

int Min(int x , int y){ return (x<y)? x:y ; }

int build( /*int tree[] ,*/ int nod , int l , int r){

    if(l==r){
        tree[nod] = ara[l];
        return ara[l];
    }
    int left = 2*nod;
    int right= 2*nod+1;
    int mid = (l+r)/2;

    tree[nod] = Min(build(left,l,mid) , build(right,mid+1,r)) ;

    return tree[nod];
}

int query( /*int tree[] ,*/ int nod , int l , int r , int L , int R /*, int sum*/){

    if(r<L || l>R)
        return 1000000000;
    if(l>=L && r<=R){
        return tree[nod];
    }
    int left = 2*nod;
    int right= 2*nod+1;
    int mid = (l+r)/2;

    return Min( query(left,l,mid,L,R) , query(right,mid+1,r,L,R) );
}

int main(){

    int t , n , q;
    scanf("%d",&t);

    for( int i=1 ; i<=t ; i++){
        scanf("%d %d",&n,&q);

        for( int j=1 ; j<=n ; j++)
            scanf("%d",&ara[j]);

        build(1,1,n);
        printf("Case %d:\n",i);
        while(q--){
            int L , R;
            scanf("%d %d",&L,&R);
            sum = 0;

            printf("%d\n",query(1,1,n,L,R));
        }
    }
}
