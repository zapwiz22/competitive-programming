/*
 * https://codeforces.com/contest/1006/submission/356681131
*/

/*
 *  author: zapwiz22
 *  created: 07-01-2026 01:51:31
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e18, MOD = 1000000007; // 998244353;

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int in[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> in[i][j];
        }
    }

    map<int, int> first[n][m];

    int total = n + m - 2;
    int half = total / 2;
    // 1 -> right , 0 -> down 
    for (int i = 0; i < (1ll << half); i++) {
        int x = 0, y = 0, val = in[0][0];
        bool ok = true;
        for (int j = 0; j < half; j++) {
            if (i & (1ll << j)) {
                y++;
            } else {
                x++;
            }
            if (x >= n || y >= m) {
                ok = false;
                break;
            }
            val ^= in[x][y];
        }
        if (ok)
            first[x][y][val]++;
    }

    int ans = 0;

    half = total - half;
    // 1 -> left , 0 -> up
    for (int i = 0; i < (1ll << half); i++) {
        int x = n - 1, y = m - 1, val = in[n - 1][m - 1];
        bool ok = true;
        for (int j = 0; j < half; j++) {
            if (i & (1ll << j)) {
                y--;
            } else {
                x--;
            }
            if (x < 0 || y < 0) {
                ok = false;
                break;
            }
            val ^= in[x][y];
        }
        if (ok) {
            ans += first[x][y][k ^ val ^ in[x][y]];
        }
    }

    cout << ans << endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        cerr << "Case #" << i << ": " << endl;
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}