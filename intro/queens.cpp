#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;
int helper(vector<string>&board,unordered_set<int>&brows,unordered_set<int>&bcols,unordered_set<pair<int,int>>diags,int count){
    if(count==8){
        return 1;
    }

    int ans=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(brows.find(i)!=brows.end() || board[i][j]=='*'){
                continue;
            }else if(bcols.find(j)!=bcols.end()){
                continue;
            }else{
                brows.insert(i);
                bcols.insert(j);
                unordered_set<pair<int,int>>temp=diags;
                int i1=i;
                int j1=j;
                while(i1<8 && j1<8){
                    temp.insert({i,j});
                    i++;
                    j++;
                }
                i1=i;
                j1=j;
                while(i1>=0 && j1>=0){
                    temp.insert({i,j});
                    i--;
                    j--;
                }
                ans+=helper(board,brows,bcols,count+1);
                brows.erase(i);
                bcols.erase(j);
            }
        }
    }
    return ans;
}
int main(){
    vector<string>board(8);
    for(int i=0;i<8;i++){
        cin>>board[i];
    }
    unordered_set<int>brows;
    unordered_set<int>bcols;

    // for(int i=0;i<board.size();i++){
    //     for(int j=0;j<board[i].size();i++){
    //         if(board[i][j]=='*'){
    //             brows.insert(i);
    //             bcols.insert(j);
    //         }
    //     }
    // }

    int ans=helper(board,brows,bcols,0);
    cout<<ans<<endl;
}

