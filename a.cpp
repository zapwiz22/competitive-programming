#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
// freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout),
// freopen("error.txt", "w", stderr);
#include "debug.h"
#else
#define debug(...)
#endif

/* Template */
#define mod 1000000007
#define mod1 998244353
#define inf 1e15
#define linf 2e18
#define nl '\n'

/* Disjoint Set */
class DisjointSet {
private:
  vector<ll> par, sizes;

public:
  DisjointSet(ll n) : par(n), sizes(n, 1) { iota(par.begin(), par.end(), 0); }
  ll find(ll x) { return (par[x] == x ? x : par[x] = find(par[x])); }
  bool unite(ll x, ll y) {
    ll x_root = find(x), y_root = find(y);
    if (x_root == y_root)
      return false;
    if (sizes[x_root] < sizes[y_root])
      swap(x_root, y_root);
    sizes[x_root] += sizes[y_root];
    par[y_root] = x_root;
    return true;
  }
  ll tree_len(ll x) { return sizes[find(x)]; }
};

/* Binary Exponentiation */
ll binexpo(ll a, ll b, ll MOD) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = 1ll * res * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return res;
}

/* Fermat's Little Theorem - Modular Inverse */
ll modinv(ll x, ll MOD) { return binexpo(x, MOD - 2, MOD); }

/* Modular Operations */
ll modadd(ll a, ll b, ll MOD) { return ((a % MOD) + (b % MOD)) % MOD; }
ll modsub(ll a, ll b, ll MOD) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
ll modmul(ll a, ll b, ll MOD) { return ((a % MOD) * (b % MOD)) % MOD; }

const ll mxeN = 1e5 + 1;

ll n, m, q, a, b, c, k, u, v, w, x, l, r, ans;
string s;

vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> par, dist;
bool ok;

void solve() {
  cin >> n >> q;
  vector<ll> vec, pref(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    pref[i + 1] = pref[i] + x;
    vec.push_back(x);
  }
  while (q--) {
    cin >> a >> b;
    cout << pref[b] - pref[a - 1] << nl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  ll TESTS = 1;
  // cin >> TESTS;
  while (TESTS--) {
    solve();
  }
  return 0;
}
