#include <iostream>

using namespace std;

int main(){
    long long n;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        long long temp;
        cin>>temp;
        sum+=temp;
    }
    long long actualSum=(n*(n+1))/2;
    long long ans=actualSum-sum;
    cout<<ans;
    return 0;
}