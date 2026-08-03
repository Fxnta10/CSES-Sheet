#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long a,b;
        cin>>a>>b;
        while(a!=0 && b!=0){
            if(a>=b){
                a-=2;
                b-=1;
            }else{
                a-=1;
                b-=2;
            }
        }
        if(a==0 && b==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}