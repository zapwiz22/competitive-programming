/*
* articulation points (cut vertices)
* are vertices in an undirected graph whose removal increases the number of connected components.
*/
vector<bool> vis(n, false);
vector<int> tin(n), low(n);
set<int> st;
int t = 0;
function<void(int, int)> dfs = [&](int u, int p) {
    int child = 0;
    vis[u] = true;
    tin[u] = low[u] = ++t;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) st.insert(u);
            child++;
        }
    }
    if (p == -1 && child > 1) st.insert(u);
};

for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i, -1);
}