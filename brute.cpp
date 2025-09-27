// by leviackerman001 - 25/5/2025

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto& v : a) cin >> v;

    if (k == 1) {
        if (x != n) {
            cout << "-1\n";
            return 0;
        }
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        cout << sum << '\n';
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(x + 1, -1));
    for (int i = 0; i < min(n, k); ++i) dp[i][1] = a[i];

    for (int j = 2; j <= x; ++j) {
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            ll p = (i ? dp[i - 1][j - 1] : -1);
            if (p != -1) {
                while (!dq.empty() && dp[dq.back()][j - 1] <= p)
                    dq.pop_back();
                dq.push_back(i - 1);
            }
            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();
            if (!dq.empty() && dp[dq.front()][j - 1] != -1)
                dp[i][j] = dp[dq.front()][j - 1] + a[i];
        }
    }

    ll res = -1;
    for (int i = n - k; i < n; ++i)
        res = max(res, dp[i][x]);

    cout << res << '\n';
}
