template <class S,
    S(*op)(S, S),
    S(*e)(),
    class F,
    S(*mapping)(F, S),
    F(*composition)(F, F),
    F(*id)()>
struct lazy_segtree {
public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int32_t n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int32_t(v.size())) {
        log = 64 - __builtin_clzll(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int32_t i = 0; i < _n; i++) d[size + i] = v[i];
        for (int32_t i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int32_t p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int32_t i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int32_t i = 1; i <= log; i++) update(p >> i);
    }

    S get(int32_t p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int32_t i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int32_t l, int32_t r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int32_t i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int32_t p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int32_t i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int32_t i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int32_t l, int32_t r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int32_t i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int32_t l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int32_t i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int32_t max_right(int32_t l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int32_t max_right(int32_t l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int32_t i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int32_t min_left(int32_t r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int32_t min_left(int32_t r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int32_t i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int32_t _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int32_t k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int32_t k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int32_t k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
