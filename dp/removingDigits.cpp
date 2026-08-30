#include<iostream>
#include<vector>
#include<string>
#include <climits>

using namespace std;

int helper(int n,string num,vector<int>&dp){
    if(n<0) return INT_MAX;
    if(n==0) return 0;
    int ans=INT_MAX;

    if(dp[n]!=-1) return dp[n];
    for(auto c:num){
        if(c=='0') continue;
        int temp=n-(c-'0');
        string temp2=to_string(temp);
        int t=helper(temp,temp2,dp);
        if(t!=INT_MAX) ans = min(ans,t+1);
    }
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    string num=to_string(n);
    vector<int>dp(n+1,-1);
    cout<<helper(n,num,dp)<<endl;    
}