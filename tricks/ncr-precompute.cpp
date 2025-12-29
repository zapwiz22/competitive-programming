/*
if the mod value is not necerssarily prime then can't use modinv
instead find formulas so that all can be computed as sums, differneces and
products and no modinv is required

example as in the below question of Atcoder
https://atcoder.jp/contests/abc425/tasks/abc425_e
submission: https://atcoder.jp/contests/abc425/submissions/69688709

got to know that if smaller n and r values then we can precompute ncr as
nCr = (n-1)C(r-1) + (n-1)Cr

also to find s = (c1 + c2 + c3 + ... + cn)!/[(c1!)*(c2!)*...*(cn!)]
we can write s as
s = [(c1)!/(c1!)]*[(c1+c2)!/(c2!)]*[(c1+c2+c3)!/c3!]*...*[(c1+c2+...+cn)!/cn!]
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

/* Template */
namespace jk {
#define mod 1000000007
#define mod1 998244353
#define inf 1e15
#define linf 2e18
#define nl '\n'

	/* Segment Tree */
	struct SegmentTree {
		vector<ll> tree;
		ll n;
		SegmentTree(ll n) { tree.resize(2 * n, 0); this->n = n; }
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
	};

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

#define int long long 
tuple<int, int, int> extendedGCD(int a, int b) {
	if (b == 0) return {a, 1, 0};
	auto [gcd, x1, y1] = extendedGCD(b, a % b);
	return {gcd, y1, x1 - (a / b) * y1};
}

int modInverse(int q, int M) {
	auto [gcd, x, y] = extendedGCD(q, M);
	return (x % M + M) % M;
}

int modularCalculation(int p, int q, int M) {
	int qInv = modInverse(q, M);
	return (1LL * p * qInv) % M;
}
#undef int 

const ll mxeN = 5e3 + 1;

ll n, m, q, a, b, c, k, u, v, w, x, y, z, l, r, ans;
string s;

vector<vector<ll>> ncr(mxeN, vector<ll>(mxeN, 0));

void solve() {
	ll  sum = 0;
	cin >> x;
	vector<ll> vec(x);
	for (ll& x : vec) {
		cin >> x;
	}
	ans = 1;
	for (auto& val : vec) {
		sum += val;
		ans *= ncr[sum][val];
		ans = ans % m;
	}
	cout << ans << nl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll TESTS = 1;
	cin >> TESTS;

	cin >> m;

	ncr[0][0] = 1;
	for (int i = 1; i < mxeN; i++) {
		ncr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % m;
		}
	}

	while (TESTS--) {
		solve();
	}
	return 0;
}