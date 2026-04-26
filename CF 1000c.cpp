#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<long long, long long> mp;

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }

    vector<long long> ans(n + 1, 0);

    long long prev = 0, cnt = 0;
    bool first = true;

    for (auto &it : mp) {
        if (!first) {
            long long x = it.first;
            ans[cnt] += x - prev;
        }
        cnt += it.second;
        prev = it.first;
        first = false;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
