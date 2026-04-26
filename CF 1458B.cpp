#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }

    const int MAX = 10000;
    vector<vector<double>> dp(n + 1, vector<double>(MAX + 1, -1e18));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int k = 0; k <= MAX - b[i]; k++) {
                if (dp[j][k] < -1e17) continue;
                dp[j + 1][k + b[i]] = max(dp[j + 1][k + b[i]], dp[j][k] + a[i]);
            }
        }
    }

    cout << fixed << setprecision(10);
    for (int k = 1; k <= n; k++) {
        double res = 0;
        for (int s = 0; s <= MAX; s++) {
            if (dp[k][s] < -1e17) continue;
            res = max(res, min((double)s, (dp[k][s] + sum) / 2.0));
        }
        cout << res << " ";
    }

    return 0;
}
