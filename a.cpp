#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define int long long 

#define mod 1000000007
#define mod1 998244353
#define inf (long long)1e15
#define linf (long long)2e18

const int N = 1e3 + 1;

void solve() {

}

#undef int 

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int TESTS = 1;
	cin >> TESTS;

	for (int Case = 1; Case <= TESTS; Case++) {
		debug(Case);
		solve();
	}

	return 0;
}
