/*
    Rasesh Bhaiya's segtree submission for 
    https://codeforces.com/contest/1709/submission/331688742 
    1709 D question 
*/


#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define int long long int
// Debug Macro
#if DEBUG
#define deb(x) cerr << #x << " = " << x << endl
#else
#define deb(x)
#endif

// Debug function for containers
template <typename T>
void debug(const T &container)
{
#ifndef DEBUG
    return;
#endif
    for (const auto &elem : container)
        cerr << elem << " ";
    cerr << endl;
}
#define read(a, n)              \
    for (int i = 0; i < n; ++i) \
        cin >> a[i];
#define print(a, n)             \
    for (int i = 0; i < n; ++i) \
        cout << a[i] << " \n"[i == n - 1];
#define trav(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define f(a, start, end) for (int a = start; a < end; a++)
#define ft(a, end) for (int a = 0; a < end; a++)
#define fi(a, start, end, inc) for (int a = start; a < end; a += inc)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
// #define PI 3.14159265358979323846

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
// const int MOD = 998244353;
template <class T, class U>
// source: https://github.com/sharmaharisam/Generic_all_purpose_segtree/blob/main/Segtree.cpp
struct LSegTree
{
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
    LSegTree(int n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }

    T combine(T l, T r)
    {
        // combine 2 nodes
        T ans = max(l, r);
        return ans;
    }

    void buildUtil(int v, int tl, int tr, vector<T> &a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }

    T apply(T curr, U upd, int tl, int tr)
    {
        // transform current answer curr to new answer upd for a node
        T ans = max(curr, upd);
        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, int tl, int tr)
    {
        // update lazy node with old and new values combined..
        U ans = old_upd;
        ans = max(ans, new_upd);
        return ans;
    }

    void push_down(int v, int tl, int tr)
    {
        if (lazy[v] == identity_update)
            return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n)
        {
            int tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(int v, int tl, int tr, int l, int r)
    {
        push_down(v, tl, tr);
        if (l > r)
            return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        int tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(int v, int tl, int tr, int l, int r, U upd)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r)
            return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            int tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }

    void build(vector<T> a)
    {
        assert((int)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }
    T query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(int l, int r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(m);
    read(a, m);
    auto st = LSegTree<int, int>(m, LLONG_MIN, 0);
    st.build(a);
    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        if(y1>y2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if (abs(x1 - x2) % k != 0 || abs(y1 - y2) % k != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            int up = n - x1;
            up = up / k * k;
            if (st.query(y1 - 1, y2-1) < x1 + up)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}