#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long base = 31;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<long long> st;
    vector<long long> p(600005);
    p[0] = 1;
    for (int i = 1; i < 600005; i++) p[i] = (p[i - 1] * base) % mod;

    while (n--) {
        string s;
        cin >> s;
        long long h = 0;
        for (int i = 0; i < s.size(); i++) {
            h = (h + (s[i] - 'a' + 1) * p[i]) % mod;
        }
        st.insert(h);
    }

    while (m--) {
        string s;
        cin >> s;

        long long h = 0;
        for (int i = 0; i < s.size(); i++) {
            h = (h + (s[i] - 'a' + 1) * p[i]) % mod;
        }

        bool ok = false;

        for (int i = 0; i < s.size() && !ok; i++) {
            long long cur = h;
            long long old = (s[i] - 'a' + 1) * p[i] % mod;

            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[i]) continue;
                long long nw = (c - 'a' + 1) * p[i] % mod;
                long long nh = (cur - old + nw) % mod;
                if (nh < 0) nh += mod;
                if (st.count(nh)) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
