#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>map(n,vector<char>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    pair<int,int>start;
    pair<int,int>end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp=='A') start={i,j};
            if(temp=='B') end={i,j};
            map[i][j]=temp;
        }
    }

    queue<pair<pair<int,int>,string>> q;
    q.push({start,""});
    vis[start.first][start.second] = true;
    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        int i=curr.first.first;
        int j=curr.first.second;
        if(curr.first==end){
            cout<<"YES"<<endl;
            cout<<curr.second.size()<<endl;
            cout<<curr.second<<endl;
            return 0;
        }
        vector<pair<string, vector<int>>> dirs = {
            {"L", {0, -1}},
            {"R", {0, 1}},
            {"U", {-1, 0}},
            {"D", {1, 0}}
        };
        
        for(auto it:dirs){
            auto direction=it.first;
            auto delta=it.second;

            int ni=i+delta[0];
            int nj=j+delta[1];
            
            if(ni>=0 && nj>=0 && ni<n && nj<m && (map[ni][nj]=='.' || map[ni][nj]=='B') && !vis[ni][nj]){
                q.push({{ni,nj},curr.second+direction});
                vis[ni][nj]=true;
            }
        }
    }
    cout<<"NO"<<endl;
}