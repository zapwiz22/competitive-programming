#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node {
    int lazy;
    int sum;
    node() {
        lazy = 0;
        sum = 0;
    }
};

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

node t[4 * 200200];

void push(int id, int l, int r) {
    if (t[id].lazy) {
        // if there is lazy then apply and push down 

        // apply logic.
        t[id].sum += (r - l + 1) * t[id].lazy;

        // push down logic if not leaf.
        if (l != r) {
            t[id << 1 | 1].lazy += t[id].lazy;
            t[id << 1].lazy += t[id].lazy;
        }

        // clear.
        t[id].lazy = 0; 
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id].lazy = t[id].sum = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = merge(t[id << 1], t[id << 1 | 1]); 
}

void update(int id, int l, int r, int lq, int rq, int val) {
    push(id, l, r);
    if (lq > r || rq < l) return;
    if (lq <= l && rq >= r) { 
        t[id].lazy += val;
        push(id, l, r);
        return;
    }
    int mid = l + (r - l) / 2;
    update(i << 1, l, mid, lq, rq, val);
    update(i << 1 | 1, mid + 1, r, lq, rq, val);
    t[id] = merge(t[id << 1], t[id << 1 | 1]); 
}

node query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (lq > r || rq < l) return node();
    if (lq <= l && rq >= r) return t[id];
    int mid = l + (r - l) / 2;
    return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

void solve() {
    
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

// Range Updates and Sums CSES
#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node {
    int lazy_sum;
    int lazy_set;
    int sum;
    node() {
        lazy_sum = 0;
        lazy_set = 0;
        sum = 0;
    }
};

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

node t[4 * 200200];

void push(int id, int l, int r) {
    if (t[id].lazy_set) {
        t[id].sum = (r - l + 1) * (t[id].lazy_set + t[id].lazy_sum);
        if (l != r) {
            t[id << 1].lazy_set = t[id].lazy_set;
            t[id << 1].lazy_sum = t[id].lazy_sum;
            t[id << 1 | 1].lazy_set = t[id].lazy_set;
            t[id << 1 | 1].lazy_sum = t[id].lazy_sum;
        }
        t[id].lazy_sum = 0;
        t[id].lazy_set = 0;
    } else if (t[id].lazy_sum) {
        t[id].sum += (r - l + 1) * t[id].lazy_sum;
        if (l != r) {
            t[id << 1 | 1].lazy_sum += t[id].lazy_sum;
            t[id << 1].lazy_sum += t[id].lazy_sum;
        }
        t[id].lazy_sum = 0;
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id].lazy_sum = t[id].sum = t[id].lazy_set = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = merge(t[id << 1], t[id << 1 | 1]); 
}

void update(int id, int l, int r, int lq, int rq, int val, bool set) {
    push(id, l, r);
    if (lq > r || rq < l) return;
    if (lq <= l && rq >= r) { 
        if (set) {
            t[id].lazy_set = val;
            t[id].lazy_sum = 0;
        } else {
            t[id].lazy_sum += val;
        }
        push(id, l, r);
        return;
    }
    int mid = l + (r - l) / 2;
    update(id << 1, l, mid, lq, rq, val, set);
    update(id << 1 | 1, mid + 1, r, lq, rq, val, set);
    t[id] = merge(t[id << 1], t[id << 1 | 1]); 
}

node query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (lq > r || rq < l) return node();
    if (lq <= l && rq >= r) return t[id];
    int mid = l + (r - l) / 2;
    return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

void solve() {
    int n, q; 
    cin >> n >> q;
    vector<int> v(n);   
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        update(1, 0, n - 1, i, i, v[i], true);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, x, false);
        } else if (type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, x, true);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1).sum << endl;
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