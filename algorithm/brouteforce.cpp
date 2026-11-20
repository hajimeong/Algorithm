#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> result;
vector<int> used;

void backtracking(){
    if(result.size()==m){
        for(int i=0;i<m;i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(used[i]==0){
            result.push_back(i);
            used[i]=1;
            backtracking();
            result.pop_back();
            used[i]=0;
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=0;i<=n;i++){
        used.push_back(0);
    }

    backtracking();


}