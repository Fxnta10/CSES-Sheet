#include<iostream>
#include<vector>
using namespace std;


void dfs(int i,int j,vector<vector<char>>&map,vector<vector<bool>>&vis){
    int n=map.size();
    int m=map[0].size();
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || map[i][j]=='#' ) return;
    vis[i][j]=true;
    vector<vector<int>>dirs={{0,-1},{0,1},{1,0},{-1,0}};
    for(auto d:dirs){
        int ni= i+ d[0];
        int nj=j+d[1];
        if(ni<0 || nj<0 || ni>=n || nj>=m || vis[ni][nj]) continue;
        if(!vis[ni][nj] && map[ni][nj]=='.'){
            dfs(ni,nj,map,vis);
        }
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>>map(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    int rooms=0;
    vector<vector<bool>>vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && map[i][j]=='.'){
                dfs(i,j,map,vis);
                rooms++;
            }
        }
    }
    cout<<rooms<<endl;

}
