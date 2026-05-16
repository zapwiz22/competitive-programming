    // 1-indexed lca calculation 
    vector<vector<int>> up(n + 1, vector<int>(20, 0));
    auto dfs = [&](auto&& dfs, int u, int p) -> void {
        for (auto v : adj[u]) {
            if (v != p) {
                up[v][0] = u;
                for (int i = 1; i < 20; i++) {
                    up[v][i] = up[up[v][i - 1]][i - 1];
                }
                d[v] = d[u] + 1;
                dfs(dfs, v, u);
            }
        }
    };
    dfs(dfs, 1, 1);

    auto lca = [&](int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        int k = d[u] - d[v];
        for (int i = 19; i >= 0; i--) {
            if (k & (1ll << i)) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = 19; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    };