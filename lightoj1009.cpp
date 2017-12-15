#include<bits/stdc++.h>
using namespace std;
#define Size 20005

vector<int>vec[20005];
map<int,int>Map;
int vis[Size];
bool flage[Size];
int color[Size];
int vam , lyk;

void Dfs_vis(int u){

    vis[u] = 1;
    if(color[u]==0){
        color[u] = 1;
        vam++;
     //   printf(" vam : %d\n",u);
    }
    int sz = vec[u].size();

    for(int i=1 ; i<=sz ; i++){
        int v = vec[u][i-1];
        if(vis[v]==0){
            vis[v] = 1;
            if(color[u]==1){
                color[v]=2;
                lyk++;
       //         printf(" lyk : %d\n",v);
            }
            else{
                color[v]=1;
                vam++;
         //       printf(" vam : %d\n",v);
            }
            Dfs_vis(v);
        }
    }
}

int Dfs(int n){
    int ans = 0;

    memset(vis,0,sizeof(vis));
    memset(color,0,sizeof(vis));

    for( int i=0 ; i<n ; i++){
        if(vis[i]==0){
            vam = 0 , lyk = 0;
            Dfs_vis(i);
            ans+=max(vam,lyk);
        }
    }

    return ans;
}

int main(){

    int t , n , r , u , v , tnode;

    scanf("%d",&t);

    for( int i=1 ; i<=t ; i++){

        tnode = 0;
        scanf("%d",&r);
        for( int j=1 ; j<=r ; j++){
            scanf("%d %d",&u,&v);
            if(Map.find(u)==Map.end()){
                Map[u] = tnode;
                tnode++;
            }
            if(Map.find(v)==Map.end()){
                Map[v] = tnode;
                tnode++;
            }
            u = Map[u];
            v = Map[v];
            vec[u].push_back(v);
            vec[v].push_back(u);

        }
       // printf("tn %d\n",tnode);

        printf("Case %d: %d\n",i,Dfs(tnode));

        Map.clear();
        for(int j=0 ; j<tnode ; j++)
            vec[j].clear();

    }
}
