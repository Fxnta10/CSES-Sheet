#include<iostream>
#include<vector>

using namespace std;
const int MOD=1000000007;
long long helper(int n,vector<long long>&dp){
    if(n<0) return 0;
    if(n==0) return 1;
    long long ans=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=6;i++){
        ans= ans+ helper(n-i,dp);
    }
    return dp[n]=ans%MOD;
}
int main(){
    long long n;
    cin>>n;
    vector<long long>dp(n+1,-1);
    long long t=helper(n,dp);
    cout<<t%MOD<<endl;
}