#include<iostream>
#include<vector>
using namespace std;
void dfs(int city,vector<vector<int>>&adj,vector<bool>&vis){
    vis[city]=true;
    for(auto n:adj[city]){
        if(!vis[n]){
            vis[n]=true;
            dfs(n,adj,vis);
        }
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>roads;
    for(int i=0;i<m;i++){
        int c1,c2;
        cin>>c1>>c2;
        roads.push_back({c1,c2});
    }

    vector<vector<int>>adj(n+1);
    for(auto r:roads){
        adj[r[0]].push_back(r[1]);
        adj[r[1]].push_back(r[0]);
    }
    int count=0;
    vector<vector<int>>ans;
    vector<bool>vis(n+1,false);
    int prev=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            if(prev==-1) prev=i;
            else{
                ans.push_back({prev,i});
                prev=i;
            }
            count++;
        }
    }

    cout<<count-1<<endl;
    for(auto r:ans){
        cout<<r[0]<<" "<<r[1]<<endl;
    }
}