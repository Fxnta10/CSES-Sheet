#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int,string>>q;
    q.push({1,"1"});
    while(!q.empty()){
        auto curr=q.front();
        int currPc=curr.first;
        string currPath=curr.second;
        if(currPc==n){
            int count=0;
            for(auto it:currPath) if(it==' ') count++;
            cout<<count+1<<endl;
            cout<<currPath<<endl;
            return 0;
        }
        q.pop();
        for(auto pc:adj[currPc]){
            if(!vis[pc]){
                string newPath=currPath+" "+to_string(pc);
                q.push({pc,newPath});
                vis[pc]=true;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
