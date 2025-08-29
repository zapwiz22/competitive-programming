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

const ll mod = 998244353;
const ll mxeN = 1e7 + 1;
vector<ll> first(mxeN), second(mxeN), c(mxeN);

void solve() {
  ll n;
  cin >> n;
  ll mxe = 0;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mxe = max(mxe, x);
    mp[x]++;
  }
  for (auto &[val, cnt] : mp) {
    for (int i = val; i < mxeN; i += val) {
      second[i] += cnt;
    }
  }
  for (int i = 1; i < mxeN; i++) {
    ll cnt = 0;
    for (int j = i; j < mxeN; j += i) {
      if (mp[j])
        cnt = (cnt % mod + mp[j] % mod) % mod;
    }
    // first[i] = cnt;
    c[i] = cnt;
    for (int j = i; j < mxeN; j += i) {
      if (mp[j]) {
        first[j] =
            (first[j] % mod + (second[j] % mod * c[i] % mod) % mod) % mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= mxe; i++) {
    // ll val = (m%mod * m%mod)%mod *
    ll val = 1ll * ((i % mod * i % mod) * first[i] % mod) % mod;
    ans = ((ans % mod) + (val % mod)) % mod;
  }
  cout << ans << endl;
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
