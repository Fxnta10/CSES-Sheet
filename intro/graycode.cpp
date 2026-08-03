#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void helper(int index,string temp,int n,vector<string>&allStrings){
    if(index==n){
        allStrings.push_back(temp);
        return;
    }
    helper(index+1,temp+"0",n,allStrings);
    helper(index+1,temp+"1",n,allStrings);
}

int main(){
    int n;
    cin>>n;
    vector<string>allStrings;
    helper(0,"",n,allStrings);
    for(auto it:allStrings){
        cout<<it<<endl;
    }
    return 0;
}

