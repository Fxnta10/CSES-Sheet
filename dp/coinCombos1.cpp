#include<iostream>
#include<vector>
using namespace std;

const int MOD=1000000007;

long long helper(long long amt,vector<long long>&coins,vector<long long>&dp){
    if(amt==0){
        return 1;
    }
    if(dp[amt]!=-1) return dp[amt];
    long long ans=0;
    for(auto coin:coins){
        if((amt-coin)>=0) ans+=helper(amt-coin,coins,dp);
    }
    return dp[amt]=ans%MOD;
}
int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<long long>dp(x+1,-1);
    long long ans=helper(x,coins,dp);
    cout<<ans%MOD<<endl;
}

