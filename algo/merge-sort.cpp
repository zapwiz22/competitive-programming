/*
 * author: zapwiz22
 * created on 16-10-2025 at 23:00:00
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

const ll N = 2e5 + 1;

struct FenwickTree {
    vector<ll> bit;
    FenwickTree(ll size) { bit.resize(size + 2, 0); }
    void update(ll i, ll delta) {
        for (; i < bit.size(); i += (i & (-i))) {
            bit[i] += delta;
            // bit[i] = (bit[i] + delta) % mod;
        }
    }
    ll get(ll i) {
        ll sum = 0;
        for (; i > 0; i -= (i & (-i))) {
            sum += bit[i];
            // sum = (sum + bit[i]) % mod;
        }
        return sum;
    }
};

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), temp1, temp2;
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;
    temp1 = a, temp2 = b;
    sort(temp1.begin(), temp1.end()), sort(temp2.begin(), temp2.end());
    for (int i = 0; i < n; i++) {
        if (temp1[i] != temp2[i]) {
            cout << "NO\n";
            return;
        }
    }

    /* merge sort code for counting inversions */

    function<ll(vector<ll>&, ll, ll)> rec = [&](vector<ll>& vec, ll low, ll high) {
        ll cnt = 0;
        ll mid = low + (high - low) / 2;
        ll i = low, j = mid + 1;
        vector<ll> temp;
        while (i <= mid and j <= high) {
            if (vec[i] < vec[j]) {
                temp.push_back(vec[i]);
                i++;
            } else {
                temp.push_back(vec[j]);
                cnt += mid - i + 1;
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(vec[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(vec[j]);
            j++;
        }
        for (int i = low; i <= high; i++) {
            vec[i] = temp[i - low];
        }
        return cnt;
    };

    function<ll(vector<ll>&, ll, ll)> f = [&](vector<ll>& vec, ll low, ll high) {
        if (low >= high) return 0ll;
        ll ans = 0, mid = low + (high - low) / 2;
        ans += f(vec, low, mid);
        ans += f(vec, mid + 1, high);
        ans += rec(vec, low, high);
        return ans;
    };

    ll first = f(a, 0, n - 1) & 1, second = f(b, 0, n - 1) & 1;
    if (first == second) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll TESTS = 1;
    cin >> TESTS;
    while (TESTS--) {
        solve();
    }
    return 0;
}