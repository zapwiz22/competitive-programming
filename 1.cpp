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

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  map<ll, ll> mp, first, second;
  ll mxe = 0;
  vector<ll> vec;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    vec.push_back(x);
    mxe = max(mxe, x);
    mp[x]++;
  }
  if (mxe > max(a, b)) {
    cout << "NO\n";
    return;
  }
  for (auto &val : vec) {
    if (!mp[a - val] and !mp[b - val]) {
      cout << "NO\n";
      return;
    } else {
      if (mp[a - val] and !first[val]) {
        // mp[a - val]--;
        // mp[val]--;
        first[val]++;
        first[a - val]++;
      }
      if (mp[b - val] and !second[val]) {
        // mp[b - val]--;
        // mp[val]--;
        second[val]++;
        second[b - val]++;
      }
    }
  }
  map<ll, bool> check;
  cout << "YES\n";
  for (auto &val : vec) {
    if (first[val] and !second[val]) {
      cout << 0 << " ";
    } else if (second[val] and !first[val]) {
      cout << 1 << " ";
    } else {
      if (!check[val]) {
        cout << 0 << " ";
        check[val] = 1;
      } else {
        cout << 1 << " ";
      }
    }
  }
  cout << endl;
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
