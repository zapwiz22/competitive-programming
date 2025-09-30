/** fenwick tree or binary-indexed tree
 * O(nlogn)
 */

const int MOD = 1e9 + 7, mxN = 2e5 + 5;

long long bit[mxN];
int n;

// building the fenwick tree adding the value for required ranges
void update(int i, long long val) {
  for (; i <= n; i += (i & (-i))) {
    bit[i] = (bit[i] + val) % MOD;
  }
}

// getting the sum of the range till i
long long sum(int i) {
  long long res = 0;
  for (; i; i -= (i & (-i))) {
    res = (res + bit[i]) % MOD;
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