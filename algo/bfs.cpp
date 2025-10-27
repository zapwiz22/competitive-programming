/*
 * author: zapwiz22
 * created on 18-10-2025 at 23:31:37
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

const ll N = 1e3 + 1;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dist(n, 0);

    function<ll(ll)> bfs = [&](ll u) {
        ll end = u;
        queue<ll> q;
        vector<ll> temp(n, -1);
        temp[u] = 0;
        q.push(u);
        while (!q.empty()) {
            end = q.front();
            q.pop();
            for (auto v : adj[end]) {
                if (temp[v] == -1) {
                    q.push(v);
                    temp[v] = temp[end] + 1;
                    dist[v] = max(dist[v], temp[v]);
                }
            }
        }
        return end;
    };

    ll end1 = bfs(0);
    ll end2 = bfs(end1);
    bfs(end2);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll TESTS = 1;
    // cin >> TESTS;
    for (int Case = 1; Case <= TESTS; Case++) {
        debug(Case);
        solve();
    }
    return 0;
}