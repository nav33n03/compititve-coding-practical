#include <bits/stdc++.h>
using namespace std;

int 

    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> freq(n + 1, 0);
    for (int x : a) freq[x]++;

    vector<int> good(n + 1, 0);
    for (int i = 0; i < n; i++) {
            int sum = a[i];
            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (sum > n) break;
                good[sum] = 1;
            }
        }

        int ans = 0;
        for (int x = 1; x <= n; x++) {
            if (good[x]) ans += freq[x];
        }

        cout << ans << "\n";
    }

    return 0;
}
