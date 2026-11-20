#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
vector<int> used;
int s;

int result=0;

void dfs(int idx,int sum){
    if(idx==n){
        if(sum==s){
            result++;
        }
        return;
    }

    dfs(idx+1, sum);
    dfs(idx+1, sum+arr[idx]);
}

int main(){
    cin>>n>>s;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        arr.push_back(a);
        used.push_back(0);
    }
    sort(arr.begin(), arr.end());

    dfs(0,0);

    if(s==0){
        result--;
    }
    

}