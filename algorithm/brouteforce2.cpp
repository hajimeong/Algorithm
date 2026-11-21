#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/**
 * N개의 정수가 주어진다.

주어진 정수 중 서로 다른 3개의 숫자를 선택했을 때, 세 숫자의 합이 S 이하이면서 S에 가장 가까운 값을 구하시오.

단, 반드시 3개의 숫자를 선택해야 한다.
입력
- 첫째 줄에 정수 N과 S가 주어진다.
- 둘째 줄에 N개의 정수가 공백으로 구분되어 주어진다.
출력
조건을 만족하는 세 숫자의 합 중 S에 가장 가까운 값을 출력한다.
 */
int n,s;
vector<int> v;
vector<int> used;

int result=-1;
int gap=1000001;

void func(int sum, int cnt){
    if(cnt==3){
        if(sum<=s){
            result=max(result, sum);
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i]==-1){
            used[i]=1;
            func(sum+v[i], cnt+1);
            used[i]=-1;
        }
    }
}

int main(){

    cin>>n>>s;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        v.push_back(a);
        used.push_back(-1);
    }

    func(0, 0);

    cout<<result;
}