#include "./zapwiz22.cpp"

/* Disjoint Set */
class DisjointSet {
   private:
    vector<ll> par, sizes;

   public:
    DisjointSet(ll n) : par(n), sizes(n, 1) { iota(par.begin(), par.end(), 0); }
    ll find(ll x) { return (par[x] == x ? x : par[x] = find(par[x])); }
    bool unite(ll x, ll y) {
        ll x_root = find(x), y_root = find(y);
        if (x_root == y_root)
            return false;
        if (sizes[x_root] < sizes[y_root])
            swap(x_root, y_root);
        sizes[x_root] += sizes[y_root];
        par[y_root] = x_root;
        return true;
    }
    ll tree_len(ll x) { return sizes[find(x)]; }
};
