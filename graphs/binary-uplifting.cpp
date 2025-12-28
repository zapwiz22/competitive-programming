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

// CSES: planet queries (i)

/** binary uplifting
 * O(nlogn)
 */
const int mxeN = 2e5 + 5;
ll par[30][mxeN]; // 30 -> ceil(log2(1e9)) // par[i][u] is the 2^i th parent of u

void solve() {
	ll n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> par[0][i], --par[0][i];
	}
	for (int j = 1; j < 30; j++)
		for (int i = 0; i < n; i++)
			par[j][i] = par[j - 1][par[j - 1][i]];
	while (q--) {
		ll x, k;
		cin >> x >> k, --x;
		for (int i = 0; i < 30; i++)
			if (k & (1 << i))
				x = par[i][x];
		cout << x + 1 << endl;
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
