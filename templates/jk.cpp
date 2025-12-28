/*
 *  author: zapwiz22
 *  created: $CURRENT_DATE-$CURRENT_MONTH-$CURRENT_YEAR $CURRENT_HOUR:$CURRENT_MINUTE:$CURRENT_SECOND
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e18, MOD = 1000000007; // 998244353;

void Solve() {
    
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cerr << "Case #" << i << ": " << endl;
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}