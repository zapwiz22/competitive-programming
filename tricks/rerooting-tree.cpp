/*
 * https://codeforces.com/contest/1187/submission/356618357
*/

vector<int> sub(n), dp(n, 0);
function<void(int, int)> dfs = [&](int u, int p) {
    sub[u] = 1;
    for (auto& v : adj[u]) {
        if (v == p)continue;
        dfs(v, u);
        sub[u] += sub[v];
        dp[u] += dp[v];
    }
    dp[u] += sub[u];
};
dfs(0, -1);

int mx = 0;
function<void(int, int)> rerooting = [&](int u, int p) {
    mx = max(mx, dp[u]);
    for (auto& v : adj[u]) {
        if (v != p) {
            dp[u] -= (dp[v] + sub[v]);
            sub[u] -= sub[v];
            sub[v] += sub[u];
            dp[v] += (dp[u] + sub[u]);

            rerooting(v, u);

            dp[v] -= (dp[u] + sub[u]);
            sub[v] -= sub[u];
            sub[u] += sub[v];
            dp[u] += (dp[v] + sub[v]);
        }
    }
};
rerooting(0, -1);