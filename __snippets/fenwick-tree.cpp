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
