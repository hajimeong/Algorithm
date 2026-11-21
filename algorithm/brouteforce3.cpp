
#include <iostream>
#include <vector>

using namespace std;

int n, s, k;
vector<int> v;

int result = 0;

void func(int idx, int sum, int cnt) {

    if (idx == n) {
        if (sum >= s && cnt >= k) {
            result++;
        }
        return;
    }

    func(idx + 1, sum + v[idx], cnt + 1);

    func(idx + 1, sum, cnt);
}

int main() {
    cin >> n >> s >> k;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    func(0, 0, 0);

    cout << result;

    return 0;
}
