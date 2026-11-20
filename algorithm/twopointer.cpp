#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 1. 문제 설명
N개의 양의 정수로 이루어진 수열이 주어진다.

이 수열에서 연속된 원소들의 합이 S 이상이 되는 구간을 찾으려고 한다.

조건을 만족하는 구간 중 원소의 개수가 가장 적은 구간의 길이를 출력하라.

단, 조건을 만족하는 구간이 하나도 없다면 0을 출력한다.
2. 입력 조건
- 첫 번째 줄에 수열의 길이 N과 목표 합 S가 주어진다.
- 두 번째 줄에 N개의 양의 정수가 공백으로 구분되어 주어진다.
제한 조건:
- \(1 \leq N \leq 100,000\)
- \(1 \leq S \leq 10^9\)
- \(1 \leq A_i \leq 10,000\)
- 수열의 모든 원소는 양의 정수이다.
 */

using namespace std;

int n;
int s;
vector<int> v;

int main(){
    cin>>n>>s;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        v.push_back(a);
    }

    int left=0;
    int right=0;
    int result=n+1;
    int sum=0;

    while(right<n){
        sum+=v[right];

        while(sum>=s){
            result=min(result, right-left+1);
            sum-=v[left];
            left++;
        }
        right++;
    }

    if(result==n+1){
        result=0;
    }

    cout<<result;
}
