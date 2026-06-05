const int N = 200000;
int a[N];
int seg[2 * N];
int SZ;
void build(int n) {
    SZ = n;
    for (int i = 0; i < n; i++) seg[i + SZ] = a[i];
    for (int i = SZ - 1; i >= 1; i--) seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}
void update(int pos, int val) {
    pos += SZ;
    seg[pos] = val;
    for (pos >>= 1; pos; pos >>= 1) seg[pos] = max(seg[pos << 1], seg[pos << 1 | 1]);
}
int query(int l, int r) {   // inclusive
    int res = 0;
    l += SZ;
    r += SZ + 1;
    while (l < r) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
        l >>= 1;
        r >>= 1;
    }
    return res;
}

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}

int query_hld(int a, int b, int n) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

/* how to use 
    init(adj);
    for (int i = 0; i < n; i++) a[pos[i]] = val[i];

    build(n);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x, --s;
            update(pos[s], x);
        } else {
            int a, b; cin >> a >> b;
            --a, --b;
            cout << query_hld(a, b, n) << endl;
        }
    }
*/