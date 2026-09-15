#include <iostream>

using namespace std;

int n,m;
int arr[10];

void dfs(int start, int depth){
    if(depth==m){
        for(int i=0;i<depth;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    for(int i=start+1;i<=n;i++){
            arr[depth]=i;
            dfs(i,depth+1);
    }
}

int main(){
    cin>>n>>m;

    dfs(0,0);
}