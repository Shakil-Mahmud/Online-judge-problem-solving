#include<bits/stdc++.h>
#define pii pair<int,int>
#define Size 25
using namespace std;

int visited[Size][Size];
char cell[Size][Size];
int fx[] = {0, 0,1,-1};
int fy[] = {1,-1,0, 0};

int row , column , counter=0;

int bfs(int sx , int sy ){

    queue<pii>q;
    q.push(pii(sx,sy));
    visited[sx][sy] = 1;

    while(!q.empty()){
        pii top = q.front();
        q.pop();
        counter++;

        for(int i=0 ; i<4 ; i++){
            int tx = top.first+fx[i];
            int ty = top.second+fy[i];
            if( tx>=0 && tx<row && ty>=0 && ty<column && cell[tx][ty]!='#'){
                if(visited[tx][ty]==0){
                    visited[tx][ty] = 1;
                    q.push(pii(tx,ty));
                }
            }
        }
    }
    return counter;
}

int main(){

    int T;
    scanf("%d",&T);

    for(int Case=1 ; Case<=T ; Case++){
        memset(visited,0,sizeof(visited));
        int sx , sy ;
        scanf("%d %d",&column,&row);

        for( int i=0 ; i<row ; i++){
            for( int j=0 ; j<column ; j++){
                scanf(" %c",&cell[i][j]);
                if(cell[i][j]=='@'){
                    sx = i;
                    sy = j;
                }
            }
        }
        printf("Case %d: %d\n",Case,bfs(sx,sy));
        counter = 0;
    }
}
