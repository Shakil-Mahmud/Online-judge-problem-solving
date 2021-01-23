#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


int fx[] = {0, 0,1,-1};
int fy[] = {1,-1,0, 0};

int bfs(pii s , pii ss , int r , int c , int mat[25][25]){

    int visited[r+2][c+2];
    int d[r+2][c+2];
    memset(visited,0,sizeof(visited));

    visited[ss.first][ss.second]=1;
    d[ss.first][ss.second]=0;
    queue<pii>Q;
    Q.push(ss);

    while(!Q.empty()){
        pii u = Q.front();
        Q.pop();

        for( int i=0 ; i<4 ; i++){
            int x = u.first + fx[i];
            int y = u.second + fy[i];

            if( x>=0 && x<r && y>=0 && y<c && visited[x][y]==0 && mat[x][y]!=-1){
                visited[x][y]=1;
                Q.push(make_pair(x,y));
                d[x][y] = d[u.first][u.second]+1;
            }
        }
    }

    return d[s.first][s.second];
}

int main(){

    int t;
    int mat[25][25];
    char ch;
    int r , c ;

    pii s,s1,s2,s3;
    scanf("%d",&t);

    for( int i=1 ; i<=t ; i++){
        scanf("%d %d",&r,&c);
        memset(mat,0,sizeof(mat));

        for(int j=0 ; j<r ; j++){
            for(int k=0 ; k<c ; k++){
                scanf(" %c",&ch);

                if(ch=='#' || ch=='m')
                    mat[j][k] = -1;
                else if(ch=='a')
                    s1 = make_pair(j,k);
                else if(ch=='b')
                    s2 = make_pair(j,k);
                else if(ch=='c')
                    s3 = make_pair(j,k);
                else if(ch=='h')
                    s = make_pair(j,k);
            }
        }

        int ans = bfs(s,s1,r,c,mat);

        int temp = bfs(s,s2,r,c,mat);
        if(temp>ans)
            ans = temp;

        temp = bfs(s,s3,r,c,mat);
        if(temp>ans)
            ans = temp;
        printf("Case %d: %d\n",i,ans);
    }
}
