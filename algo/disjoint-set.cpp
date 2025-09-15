class DisjointSet {
private:
  vector<ll> parent, size;

public:
  DisjointSet(int len) : parent(len), size(len, 1) {
    for (int i = 0; i < len; i++)
      parent[i] = i;
  }

  ll find(ll x) { return (parent[x] == x ? x : (parent[x] = find(parent[x]))); }

  bool unite(ll x, ll y) {
    ll x_root = find(x);
    ll y_root = find(y);
    if (x_root == y_root)
      return false;
    if (size[x_root] < size[y_root])
      swap(x_root, y_root);
    size[x_root] += size[y_root];
    parent[y_root] = x_root;
    return true;
  }

  bool connected(ll x, ll y) { return find(x) == find(y); }

  ll length(ll x) { return size[find(x)]; }
};
