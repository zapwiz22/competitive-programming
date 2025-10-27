/*
 * author: zapwiz22
 * created on 19-10-2025 at 20:59:56
 */

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define mod 1000000007
#define mod1 998244353
#define inf 1e15
#define linf 2e18
#define nl '\n'

const ll N = 2e5 + 10;
vector<bool> check(N, true);
vector<ll> primes;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll mxe = 0;
    for (ll& x : a) {
        cin >> x;
        mxe = max(mxe, x);
    }
    for (ll& x : b) {
        cin >> x;
    }
    vector<ll> cnt(mxe + 5, 0);
    for (auto val : a) {
        cnt[val]++;
    }
    debug(cnt);
    ll ans = 2;
    for (auto val : primes) {
        if (val > mxe) {
            break;
        }
        ll curr = 0, second = 0;
        for (int i = val; i <= mxe + 2; i += val) {
            if (cnt[i]) {
                curr += cnt[i];
            }
            if (cnt[i - 1]) second += cnt[i - 1];
            if (curr > 1) {
                cout << 0 << nl;
                return;
            }
            if (curr and second) {
                ans = min(1ll, ans);
            }
        }
    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll TESTS = 1;
    cin >> TESTS;

    for (int i = 2; i < N; i++) {
        if (check[i]) {
            primes.push_back(i);
            for (int j = i; j < N; j += i) {
                check[j] = false;
            }
        }
    }

    for (int Case = 1; Case <= TESTS; Case++) {
        debug(Case);
        solve();
    }
    return 0;
}