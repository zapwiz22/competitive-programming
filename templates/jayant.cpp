#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e18, MOD = 1000000007; // 998244353;

void Solve() {

}

#undef int

int main() {
#ifdef ZAP
    freopen("int", "r", stdin), freopen("out1", "w", stdout), freopen("err", "w", stderr);
#endif
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cerr << "Case #" << i << ": " << endl;
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}