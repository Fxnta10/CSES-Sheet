#include<iostream>
#include<vector>
#include<climits>

using namespace std;
long long minDiff=LLONG_MAX;
void helper(int index,int n,long long grp1,long long grp2,vector<long long>&v){
    if(index==n){
        long long diff=abs(grp1-grp2);
        minDiff=min(minDiff,diff);
        return;
    }

    helper(index+1,n,grp1+v[index],grp2,v);
    helper(index+1,n,grp1,grp2+v[index],v);
}

int main(){
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    helper(0,n,0,0,v);
    cout<<minDiff<<endl;
}