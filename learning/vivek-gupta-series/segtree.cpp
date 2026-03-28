// Range Updates
#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node {
    int sum;
    node() {
        sum = 0;
    }
};

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

node t[4 * 200200];

void build(int id, int l, int r) {
    if (l == r) {
        t[id].sum = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }
    if (l == r) {
        t[id].sum += val;
        return;
    }
    int mid = l + (r - l) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq) {
    if (r < lq || rq < l) {
        return node();
    }
    if (lq <= l && rq >= r) {
        return t[id];
    }
    int mid = l + (r - l) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build(1, 0, n - 1);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(1, 0, n - 1, a - 1, u);
            update(1, 0, n - 1, b, -u);
        } else {
            int k; cin >> k;
            cout << v[k - 1] + query(1, 0, n - 1, 0, k - 1).sum << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

// Hotel Queries CSES 
#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node {
    int mx;
    node() {
        mx = 0;
    }
};

node merge(node a, node b) {
    node ans;
    ans.mx = max(a.mx, b.mx);
    return ans;
}

node t[4 * 200200];

void build(int id, int l, int r) {
    if (l == r) {
        t[id].mx = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }
    if (l == r) {
        t[id].mx += val;
        return;
    }
    int mid = l + (r - l) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

int query(int id, int l, int r, int x) {
    if (l == r) {
        return l;
    }
    if (t[2 * id].mx >= x) return query(2 * id, l, (r + l) / 2, x);
    else return query(2 * id + 1, (r + l) / 2 + 1, r, x);
}

void solve() {
    int n, m;
    cin >> n >> m;

    build(1, 0, n - 1);
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        update(1, 0, n - 1, i, h[i]);
    }

    while (m--) {
        int x; cin >> x;
        if (t[1].mx < x) cout << 0 << " ";
        else {
            int idx = query(1, 0, n - 1, x);
            update(1, 0, n - 1, idx, -x);
            cout << idx + 1 << " ";
        }
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
