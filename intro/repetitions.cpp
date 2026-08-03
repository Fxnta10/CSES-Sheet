#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();

    int maxLen=0;
    int currLen=0;
    for(int i=0;i<n;i++){
        if(i>0 && s[i]==s[i-1]){
            currLen++;
        }else{
            currLen=1;
        }
        maxLen=max(maxLen,currLen);
    }
    cout<<maxLen<<endl;
    return 0;
}