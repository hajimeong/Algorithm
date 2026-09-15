#include <iostream>

using namespace std;

int n,m;
int visited[10];
int arr[10];

void dfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1;i<=n;i++){
        if(visited[i]!=1){
            arr[depth]=i;
            visited[i]=1;
            dfs(depth+1);
            visited[i]=0;
        }
    }
}

int main(){
    cin>>n>>m;

    dfs(0);
}