/* Disjoint Set */
class DisjointSet {
   private:
    vector<int> par, sizes;

   public:
    DisjointSet(int n) : par(n), sizes(n, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x ? x : par[x] = find(par[x])); }
    bool unite(int x, int y) {
        int x_root = find(x), y_root = find(y);
        if (x_root == y_root)
            return false;
        if (sizes[x_root] < sizes[y_root])
            swap(x_root, y_root);
        sizes[x_root] += sizes[y_root];
        par[y_root] = x_root;
        return true;
    }
    int tree_len(int x) { return sizes[find(x)]; }
};
