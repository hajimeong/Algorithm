#include <iostream>
#include <vector>

using namespace std;

int n;


int main(){
    cin>>n;

    vector<vector<int>> v(n, vector<int>(n,0));

    int x=0;
    int y=0;

    int sz=n-1;

    for(int i=0;i<n*n;i++){
        cout<<"("<<x<<", "<<y<<") \n";
        if(v[x][y]==0){
            v[x][y]=i+1;
        }
        if(x==sz){
            y++;
            continue;
        }else if(y==sz){
            x--;
            continue;
        }else if(x==n-sz){
            y--;
            sz-=1;
            continue;
        }else if(y==n-sz){
            x++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }

}