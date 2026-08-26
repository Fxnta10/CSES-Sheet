#include<iostream>
#include<vector>

using namespace std;

bool visited[7][7];

int helper(int i, int j, int index, string path, string desc){
    if(i<0 || j<0 || i>=7 || j>=7) return 0;
    if(visited[i][j]) return 0;
    if(i==6 && j==0){
        return index == 48;
    }
    if(index == 48) return 0;
    visited[i][j] = true;
    int ans=0;
    if(desc[index]=='?' || desc[index]=='U') ans += helper(i-1,j,index+1,path+'U',desc);

    if(desc[index]=='?' || desc[index]=='D') ans += helper(i+1,j,index+1,path+'D',desc);

    if(desc[index]=='?' || desc[index]=='R') ans += helper(i,j+1,index+1,path+'R',desc);

    if(desc[index]=='?' || desc[index]=='L') ans += helper(i,j-1,index+1,path+'L',desc);
    visited[i][j] = false;
    return ans;
}

int main(){
    string desc;
    cin>>desc;
    int ans=helper(0,0,0,"",desc);
    cout<<ans<<endl;
    return 0;
}