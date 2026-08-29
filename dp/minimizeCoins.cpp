#include<iostream>
#include <vector>
#include <climits>

using namespace std;

long long helper(long long amt,vector<long long>&coins,vector<long long>&dp){
    if(amt==0) return 0;
    int ans=INT_MAX;
    if(dp[amt]!=-1) return dp[amt];
    for(int i=0;i<coins.size();i++){
        if((amt-coins[i])>=0){
            int t=helper(amt-coins[i],coins,dp);
            ans=min(ans,t);
        }
    }
    if(ans==INT_MAX)return dp[amt]=INT_MAX;
    return dp[amt]=ans+1;
}

int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long>coins(n);
    vector<long long>dp(x+1,-1);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    long long ans=helper(x,coins,dp);
    if(ans==INT_MAX){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}