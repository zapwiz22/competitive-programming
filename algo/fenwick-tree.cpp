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