#include<iostream>
#include<string>
#include<vector>
using namespace std;
void helper(int index,int n,vector<string>&allStrings,string temp,vector<int>&freq){
    if(index==n){
        allStrings.push_back(temp);
        return;
    }

    for(int i=0;i<26;i++){
        char c='a'+i;
        if(freq[i]>0){
            freq[i]--;
            helper(index+1,n,allStrings,temp+c,freq);
            freq[i]++;
        }
    }
    return;
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>freq(26,0);
    for(auto it:s){
        int x=it-'a';
        freq[x]++;
    }
    vector<string>allStrings;
    helper(0,n,allStrings,"",freq);
    cout<<allStrings.size()<<endl;
    for(auto str:allStrings){
        cout<<str<<endl;
    }
    return 0;
}

