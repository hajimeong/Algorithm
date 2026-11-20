#include <iostream>
#include <vector>

using namespace std;

int n,q;
vector<int> v;
vector<int> prefix;
vector<int> result;

/**
 * 1. 문제 설명
N개의 정수로 이루어진 수열이 주어진다.

이후 Q개의 질문이 주어진다. 각 질문에는 두 개의 정수 L과 R이 주어지며, 수열의 L번째 원소부터 R번째 원소까지의 합을 구해야 한다.

각 질문에 대해 해당 구간의 합을 출력하라.

단, 수열의 원소는 1번째부터 N번째까지 번호가 매겨져 있다.
2. 입력 조건
- 첫 번째 줄에 수열의 크기 N과 질문의 개수 Q가 주어진다.
- 두 번째 줄에 N개의 정수가 주어진다.
- 다음 Q개의 줄에는 각각 L과 R이 주어진다.
 */
int main(){
    cin>>n>>q;

    int sum=0;

    prefix.push_back(sum);
    v.push_back(0);

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;

        sum+=a;

        prefix.push_back(sum);

        v.push_back(a);
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;

        result.push_back(prefix[r]-prefix[l-1]);
    }

    for(int i=0;i<q;i++){
        cout<<result[i]<<"\n";
    }

}