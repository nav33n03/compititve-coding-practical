#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& a, long long target) {
    long long odd = 0, even = 0;
    for (auto x : a) {
        long long d = target - x;
        odd += d % 2;
        even += d / 2;
    }

    long long ans = 0;
    if (odd > even) {
        ans = 2 * odd - 1;
    } else {
        long long diff = even - odd;
        ans = 2 * odd;
        ans += (diff / 3) * 2;
        diff %= 3;
        if (diff == 1) ans += 1;
        else if (diff == 2) ans += 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long mx = *max_element(a.begin(), a.end());

        cout << min(solve(a, mx), solve(a, mx + 1)) << "\n";
    }

    return 0;
}
