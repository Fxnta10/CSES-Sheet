#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    string s;
    cin>>s;
    int oddCount=0;
    unordered_map<char,int>mp;
    for(auto it:s){
        mp[it]++;
    }
    string mid="";
    string half="";
    for(auto it:mp){
        if(it.second%2!=0){
            oddCount++;
            char x=it.first;
            int rep=it.second;
            string temp(rep,x);
            mid=temp;
        }else{
            char x=it.first;
            int rep=it.second/2;
            // cout<<x<<rep<<endl;
            string temp(rep,x);
            half+=temp;
        }
    }
    
    if(oddCount>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    string revHalf=half;
    reverse(revHalf.begin(),revHalf.end());
    string ans=half+mid+revHalf;
    cout<<ans<<endl;
    return 0;
}