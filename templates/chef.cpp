#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define int long long

constexpr int INF = 1e18, MOD = 1000000007;

struct Mint {
    int x;
    Mint(int x = 0) : x((x% MOD + MOD) % MOD) {
    }
    explicit operator int() const {
        return x;
    }
    bool operator==(const Mint& rhs) const {
        return x == rhs.x;
    }
    bool operator!=(const Mint& rhs) const {
        return !(rhs == *this);
    }
    friend Mint operator+(const Mint& l, const Mint& r) {
        return l.x + r.x;
    }
    Mint& operator+=(const Mint& o) {
        return *this = *this + o;
    }
    friend Mint operator-(const Mint& l, const Mint& r) {
        return l.x - r.x;
    }
    Mint operator-() const {
        return -x;
    }
    Mint& operator-=(const Mint& o) {
        return *this = *this - o;
    }
    friend Mint operator*(const Mint& l, const Mint& r) {
        return (int)l.x * r.x;
    }
    Mint& operator*=(const Mint& o) {
        return *this = *this * o;
    }
    Mint pow(int b) const {
        Mint ans = 1;
        Mint a = *this;
        while (b > 0) {
            if (b & 1)
                ans *= a;
            a = a * a;
            b >>= 1;
        }
        return ans;
    }
    friend Mint operator/(const Mint& l, const Mint& r) {
        return l * r.pow(MOD - 2);
    }
    Mint& operator/=(const Mint& o) {
        return *this = *this / o;
    }
    friend ostream& operator<<(ostream& os, const Mint& o) {
        return os << o.x;
    }
};

constexpr int MAX_N = 1e6 + 14;
Mint fac[MAX_N] = {1}, rfac[MAX_N] = {1};

void prep() {
    for (int i = 1; i < MAX_N; ++i)
        fac[i] = fac[i - 1] * i;
    rfac[MAX_N - 1] = 1 / fac[MAX_N - 1];
    for (int i = MAX_N - 2; i >= 0; --i)
        rfac[i] = (i + 1) * rfac[i + 1];
}

Mint c(int n, int r) {
    return n < r || r < 0 ? 0 : fac[n] * rfac[r] * rfac[n - r];
}

/* Disjoint Set */
struct DSU {
private:
    vector<int> par, sizes;

public:
    DSU(int n) : par(n), sizes(n, 1) { iota(par.begin(), par.end(), 0); }
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

/* Fenwick Tree */
struct FenwickTree {
    vector<int> bit;
    FenwickTree(int size) { bit.resize(size + 2, 0); }
    void update(int i, int delta) {
        for (; i < (int)bit.size(); i += (i & (-i))) {
            bit[i] += delta;
        }
    }
    int get(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & (-i))) {
            sum += bit[i];
        }
        return sum;
    }
};

/* Segment Tree */
struct SegmentTree {
    vector<int> tree;
    int n;
    SegmentTree(int n) {
        tree.assign(2 * n, 0);
        this->n = n;
    }
    void build() {
        for (int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    void modify(int p, int val) {
        for (tree[p += n] = val; p > 1; p >>= 1) tree[p >> 1] = tree[p] + tree[p ^ 1];
    }
    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

template <class T, class U>
// source: https://github.com/sharmaharisam/Generic_all_purpose_segtree/blob/main/Segtree.cpp
struct LSegTree {
    vector<T> st;
    vector<U> lazy;
    int n;
    T identity_element;
    U identity_update;
    /*
    identity_element: element i such that combine(i,x)=x for any x
    identity_update: update u such that apply(u,x)=x for any x
    sum: identity_element=0;identity_update=<some number that cannot occur as an element in array after updating too>
    max: identity_element=LLONG_MIN;identity_update=0;
    min: identity_element=LLONG_MAX;identity_update=0;
    */
    LSegTree(int n, T identity_element, U identity_update) {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }

    T combine(T l, T r) {
        // combine 2 nodes
        T ans = max(l, r);
        return ans;
    }

    void buildUtil(int v, int tl, int tr, vector<T>& a) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }

    T apply(T curr, U upd, int tl, int tr) {
        // transform current answer curr to new answer upd for a node
        T ans = max(curr, upd);
        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, int tl, int tr) {
        // update lazy node with old and new values combined..
        U ans = old_upd;
        ans = max(ans, new_upd);
        return ans;
    }

    void push_down(int v, int tl, int tr) {
        if (lazy[v] == identity_update)
            return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n) {
            int tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(int v, int tl, int tr, int l, int r) {
        push_down(v, tl, tr);
        if (l > r)
            return identity_element;
        if (tr < l or tl > r) {
            return identity_element;
        }
        if (l <= tl and r >= tr) {
            return st[v];
        }
        int tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(int v, int tl, int tr, int l, int r, U upd) {
        push_down(v, tl, tr);
        if (tr < l or tl > r)
            return;
        if (tl >= l and tr <= r) {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        } else {
            int tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }

    void build(vector<T> a) {
        assert((int)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }
    T query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(int l, int r, U upd) {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};

/* Z-Algorithm */
vector<int> z_func(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        z[i] = max(0LL, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            x = i, y = i + z[i], z[i]++;
        }
    }
    return z;
}

template <typename T> class SparseTable {
private:
    int n, log2dist;
    vector<vector<T>> st;

public:
    SparseTable(const vector<T>& v) {
        n = (int)v.size();
        log2dist = 1 + (int)log2(n);
        st.resize(log2dist);
        st[0] = v;
        for (int i = 1; i < log2dist; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    /** @return minimum on the range [l, r] */
    T query(int l, int r) {
        int i = (int)log2(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

class LCA {
private:
    const int n;
    const vector<vector<int>>& adj;
    SparseTable<pair<int, int>> rmq;
    vector<int> tin, et, dep;
    int timer = 0;

    /** prepares tin, et, dep arrays */
    void dfs(int u, int p) {
        tin[u] = timer;
        et[timer++] = u;
        for (int v : adj[u]) {
            if (v == p) { continue; }
            dep[v] = dep[u] + 1;
            dfs(v, u);
            et[timer++] = u;
        }
    }

public:
    // make sure the adjacency list is 0 indexed
    LCA(vector<vector<int>>& _adj)
        : n((int)_adj.size()), adj(_adj), tin(n), et(2 * n), dep(n),
        rmq(vector<pair<int, int>>(1)) {
        dfs(0, -1);
        vector<pair<int, int>> arr(2 * n);
        for (int i = 0; i < 2 * n; i++) { arr[i] = {dep[et[i]], et[i]}; }
        rmq = SparseTable<pair<int, int>>(arr);
    }

    /** @return LCA of nodes a and b */
    int query(int a, int b) {
        if (tin[a] > tin[b]) { swap(a, b); }
        return rmq.query(tin[a], tin[b]).second;
    }

    /** @return dist between node a and b */
    int dist(int a, int b) {
        int c = query(a, b);
        return dep[a] + dep[b] - 2 * dep[c];
    }
};

struct Node {
    Node* links[26];
    bool eow;  // flag for marking the end of word
    int endCount = 0;
    int prefixCount = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // insert a new node with a specific key (letter) to the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // get the node associated to a specific key (letter)
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // mark the end of the word
    void setEnd() {
        eow = true;
    }

    // check is the key is the end of the word or not
    bool isEnd() {
        return eow;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // insert word into the Trie
    // time complexity : O(len) where len is length of the word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->prefixCount++;
        }
        node->setEnd();
        node->endCount++;
    }

    // search for the word within the Trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    // return whether any word with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    // return the count of the occurrences of the string word in the Trie
    int cntWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->endCount;
    }

    // return the count of words starting with the given prefix
    int cntPrefix(string word) {
        Node* node = root;
        // int res = 0;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
                // return res;
            }
            node = node->get(word[i]);
            // res += node->prefixCount;
        }
        return node->prefixCount;
        // return res;
    }

    // erase a word in the given trie
    void erase(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            node = node->get(word[i]);
            node->prefixCount--;
        }
        node->endCount--;
    }
};

/* tarjan's algorithm for finding the bridges */
// vector<int> dp(n, 0), tin(n), low(n);
// vector<bool> vis(n, false);
// vector<pair<int, int>> bridges;
// int t = 0;
// function<void(int, int)> dfs = [&](int u, int p) {
//     vis[u] = true;
//     dp[u] = 1;
//     tin[u] = low[u] = ++t;
//     for (auto& v : adj[u]) {
//         if (v == p) continue;
//         if (vis[v]) {
//             low[u] = min(low[u], low[v]);
//         } else {
//             dfs(v, u);
//             dp[u] += dp[v];
//             low[u] = min(low[u], low[v]);
//             if (low[v] > tin[u]) {
//                 bridges.push_back({u,v});
//             }
//         }
//     }
// };
// dfs(0, -1);

/*********************** main ************************/

void Solve() {
    
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cerr << "Case #" << i << ": " << endl;
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}