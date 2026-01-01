/* tarjan's algorithm for finding the bridges */
vector<int> dp(n, 0), tin(n), low(n);
vector<bool> vis(n, false);
vector<pair<int, int>> bridges;
int t = 0;
function<void(int, int)> dfs = [&](int u, int p) {
    vis[u] = true;
    dp[u] = 1;
    tin[u] = low[u] = ++t;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], low[v]);
        } else {
            dfs(v, u);
            dp[u] += dp[v];
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                bridges.push_back({u,v});
            }
        }
    }
};
dfs(0, -1);