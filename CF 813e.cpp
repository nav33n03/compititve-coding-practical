#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    vector<int> nxt(n + 2, n + 1);

    for (auto &it : pos) {
        auto &v = it.second;
        for (int i = 0; i < (int)v.size(); i++) {
            if (i + k < (int)v.size())
                nxt[v[i]] = v[i + k];
        }
    }

    vector<vector<int>> seg(4 * (n + 2));

    function<void(int,int,int)> build = [&](int node, int l, int r) {
        if (l == r) {
            seg[node].push_back(nxt[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        auto &left = seg[node << 1];
        auto &right = seg[node << 1 | 1];
        seg[node].resize(left.size() + right.size());
        merge(left.begin(), left.end(), right.begin(), right.end(), seg[node].begin());
    };

    function<int(int,int,int,int,int,int)> query = [&](int node, int l, int r, int ql, int qr, int val) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            return lower_bound(seg[node].begin(), seg[node].end(), val) - seg[node].begin();
        }
        int mid = (l + r) >> 1;
        return query(node << 1, l, mid, ql, qr, val) +
               query(node << 1 | 1, mid + 1, r, ql, qr, val);
    };

    build(1, 1, n);

    int q;
    cin >> q;

    int last = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if (l > r) swap(l, r);

        int ans = query(1, 1, n, l, r, r + 1);
        cout << ans << "\n";
        last = ans;
    }

    return 0;
}
