#include <bits/stdc++.h>
using namespace std;
#define int long long 

/*
    codeforces.com/contest/932/problem/F
    
    for each u from 1 -> n we need to find the path with the min cost to any of the leafs 
    then if we have already calculated the above for all the members of the subtree of a 
    particular node 
    then 
    
    ans[u] = INF;
    ans[u] = (for all v in subtree of u) min(ans[u], ans[v] + a[u] * b[v])
    we need to maintain a structure that it contains m = b[v] and c = ans[v]
    and find which till the already calculated ones gives the min with a[u]

    for this we can use li-chao tree 
*/

const int N = 100100, INF = 1e18;

class Line {
public:
    int m, c;
    Line() : m(0), c(INF) {}
    Line(int slope, int intercept) : m(slope), c(intercept) {}
    int eval(int x) { return 1ll * m * x + c; }
};

class LCT {
    struct node {
        Line ln;
        int left, right;
        bool null;
        node() : left(-1), right(-1), null(true) {}
    };

    vector<node> pool;
    int low, high;
    int new_node() {
        pool.push_back(node());
        return (int)pool.size() - 1; // ID of this node 
    }
    void insert(int id, int l, int r, Line new_ln) {
        node& cur = pool[id];
        if (cur.null) {
            cur.null = false;
            cur.ln = new_ln;
            return;
        }

        int mid = l + (r - l) / 2;
        bool new_wins_mid = new_ln.eval(mid) < cur.ln.eval(mid);
        if (new_wins_mid) swap(cur.ln, new_ln);

        // new_ln is now the loser 
        if (l == r) return;

        bool loser_wins_low = new_ln.eval(l) < pool[id].ln.eval(l);
        if (loser_wins_low) {
            if (pool[id].left == -1) pool[id].left = new_node();
            insert(pool[id].left, l, mid, new_ln);
        } else {
            if (pool[id].right == -1) pool[id].right = new_node();
            insert(pool[id].right, mid + 1, r, new_ln);
        }
    }

    int query(int id, int l, int r, int x) {
        if (id == -1 || pool[id].null) return INF;
        int best = pool[id].ln.eval(x);
        int mid = l + (r - l) / 2;
        if (x <= mid) best = min(best, query(pool[id].left, l, mid, x));
        else best = min(best, query(pool[id].right, mid + 1, r, x));
        return best;
    }

public:
    LCT(int lo, int hi) : low(lo), high(hi) {
        new_node();
    }
    void add_line(int m, int c) {
        Line ln(m, c);
        insert(0, low, high, ln);
    }
    int get_min(int x) {
        return query(0, low, high, x);
    }
};

struct Node {
    LCT lct;
    vector<Line> v;
    Node() : lct(-N, N) {}
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n + 1, INF);
    auto dfs = [&](auto&& self, int u, int p) -> Node {
        Node nd;
        for (auto& v : adj[u]) {
            if (v == p) continue;
            Node tmp = self(self, v, u);
            if (tmp.v.size() > nd.v.size()) swap(nd, tmp);
            for (auto& x : tmp.v) {
                nd.v.push_back(x);
                nd.lct.add_line(x.m, x.c);
            }
        }
        if (nd.v.size() == 0) dp[u] = 0;
        else dp[u] = nd.lct.get_min(a[u]);
        nd.lct.add_line(b[u], dp[u]);
        Line nw(b[u], dp[u]);
        nd.v.push_back(nw);
        return nd;
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}