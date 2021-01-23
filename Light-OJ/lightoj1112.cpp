#include<cstdio>

int ara[100005];
int tree[4*100005];
int s , L , R;


void build(int node , int l , int r){

    if(l==r){
        tree[node] = ara[l];
        return ;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);

    tree[node] = tree[right] + tree[left];

    return;
}

void update(int node  , int l , int r , int i , int v){

    if(i<l || i>r)
        return;

    if(i>=l && i<=r){
        tree[node] = ara[i];
    }
    if(l == r){
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;

    update(left,l,mid,i,v);
    update(right,mid+1,r,i,v);

    tree[node] = tree[right] + tree[left];
}

void sum( int node , int l , int r , int i , int j){

    if(r<i || l>j)
        return;

    if(l>=i && r<=j){
        s += tree[node];
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (l+r)/2;

    sum(left,l,mid,i,j);
    sum(right,mid+1,r,i,j);

   /// return;
}

int main(){

    int n , q , t , option , i , v , j;
    scanf("%d",&t);

    for( int Case=1 ; Case<=t ; Case++){

        scanf("%d %d",&n,&q);

        for( int k=1 ; k<=n ; k++)
            scanf("%d",&ara[k]);

        build(1,1,n);
        printf("Case %d:\n",Case);

        while(q--){

            scanf("%d",&option);

            if(option==1){
                scanf("%d",&i);
                printf("%d\n",ara[i+1]);
                ara[i+1] = 0;
                update(1,1,n,i+1,v);
            }

            else if(option==2){
                scanf("%d %d",&i,&v);
                ara[i+1] += v;
                update(1,1,n,i+1,v);
            }

            else if(option==3){
                scanf("%d %d",&i,&j);
                s = 0;
                sum(1,1,n,i+1,j+1);
                printf("%d\n",s);
            }
        }

    }
}
