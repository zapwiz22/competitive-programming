#include "./zapwiz22.cpp"

/* Segment Tree */
struct SegmentTree {
    vector<ll> tree;
    ll n;
    SegmentTree(ll n) {
        tree.resize(2 * n, 0);
        this->n = n;
    }
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