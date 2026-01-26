template<typename S, typename L>
struct LazySegTree {
    int n, h;
    vector<S> t;
    vector<L> d;

    LazySegTree(int n) : n(n) {
        t.assign(2 * n, e());
        d.assign(n, id());
        h = sizeof(int) * 8 - __builtin_clz(n);
    }

    /* ---- user must define these ---- */

    static S op(const S& a, const S& b);
    static S e();

    static S mapping(const L& f, const S& x);
    static L composition(const L& f, const L& g);
    static L id();

    /* ---- internal logic ---- */

    void build() {
        for (int i = n - 1; i > 0; --i)
            t[i] = op(t[i << 1], t[i << 1 | 1]);
    }

    void apply(int p, const L& v) {
        t[p] = mapping(v, t[p]);
        if (p < n) d[p] = composition(v, d[p]);
    }

    void build(int p) {
        while (p > 1) {
            p >>= 1;
            t[p] = op(t[p << 1], t[p << 1 | 1]);
            t[p] = mapping(d[p], t[p]);
        }
    }

    void push(int p) {
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i] != id()) {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = id();
            }
        }
    }

    void range_apply(int l, int r, const L& v) {
        l += n;
        r += n;
        int l0 = l, r0 = r;

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, v);
            if (r & 1) apply(--r, v);
        }
        build(l0);
        build(r0 - 1);
    }

    S range_query(int l, int r) {
        l += n;
        r += n;
        push(l);
        push(r - 1);

        S resL = e(), resR = e();
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = op(resL, t[l++]);
            if (r & 1) resR = op(t[--r], resR);
        }
        return op(resL, resR);
    }
};
