#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> dp;

int main(){

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        board.push_back(vector<int>());
        for(int j=0;j<m;j++){
            int a;
            cin>>a;

            board[i].push_back(a);
        }
    }

    for(int i=0;i<n;i++){
        dp.push_back(vector<int>());
        for(int j=0;j<=m;j++){
            dp[i].push_back(board[i][j]);
        }
    }
    

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(board[i][j]==1){
                dp[i][j]=1+min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]);
            }
            if(board[i][j]==0){
                dp[i][j]=max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }

}