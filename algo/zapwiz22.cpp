#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1000000007, mod1 = 998244353, inf = 1e18;
const int N = 1e3 + 1;

void solve() {
    
}

#undef int

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) {
        cerr << "Case #" << i << ": " << endl;
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}