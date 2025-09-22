#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

/* Template */
const ll mxeN = 2e5 + 1;

ll n, m, q, a, b, c, k, u, v, w, x, y, z, l, r, ans;
string s;

vector<vector<ll>> adj(mxeN);
vector<bool> vis(mxeN);
vector<ll> par(mxeN), dist(mxeN);
bool ok;

namespace jk {
#define mod 1000000007
#define mod1 998244353
#define inf 1e15
#define linf 2e18
#define nl '\n'

/* Segment Tree */
vector<ll> tree(2 * mxeN, 0);
void build() {
  for (int i = n - 1; i > 0; i--)
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
void modify(ll p, ll val) {
  for (tree[p += n] = val; p > 1; p >>= 1)
    tree[p >> 1] = tree[p] + tree[p ^ 1];
}
ll query(ll l, ll r) {
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res += tree[l++];
    if (r & 1)
      res += tree[--r];
  }
  return res;
}

/* Fenwick Tree */
struct FenwickTree {
  vector<ll> bit;
  FenwickTree(ll size) { bit.resize(size + 2, 0); }
  void update(ll i, ll delta) {
    for (; i < bit.size(); i += (i & (-i))) {
      bit[i] += delta;
    }
  }
  ll get(ll i) {
    ll sum = 0;
    for (; i > 0; i -= (i & (-i))) {
      sum += bit[i];
    }
    return sum;
  }
};

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
} // namespace jk
using namespace jk;

void solve() {}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  ll TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    solve();
  }
  return 0;
}
