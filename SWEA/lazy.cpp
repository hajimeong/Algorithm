#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> v;

        for (int i = 0; i < n; i++) {
            long long a, b;
            cin >> a >> b;

            v.push_back({b, a});
        }

        sort(v.begin(), v.end(), greater<pair<long long, long long>>());

        long long result = 1e18;

        for (auto it : v) {
            if(min(result,it.first)-it.second>=0){
            	result = min(result, it.first) - it.second;
            }else break;
        }

        cout << result << '\n';
    }

    return 0;
}