#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string nums;
int n;
vector<int> v;
int answer=0;
map<pair<string, int>, bool> visited;

void dfs(string s, int cnt){
    if(visited[{s, cnt}]) return;

    visited[{s, cnt}]=true;

    if(cnt==n){
        answer=max(answer, stoi(s));
        return;
    }

    for(int i=0;i<nums.length()-1;i++){
        for(int j=i+1;j<nums.length();j++){
            swap(s[i],s[j]);
            dfs(s, cnt+1);
            swap(s[i], s[j]);
        }
    }

}


int main(){
    cin>>nums>>n;

    dfs(nums, 0);

    cout<<answer;

}