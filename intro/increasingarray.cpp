#include<iostream>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long count=0;
    long long prev;
    cin>>prev;

    for(long long i=1;i<n;i++){
        long long temp;
        cin>>temp;
        if(temp<prev){
            long long tempCount=prev-temp;
            count=count+tempCount;
            prev=temp+(prev-temp);
        }else{
            prev=temp;
        }
    }
    cout<<count;
    return 0;
}