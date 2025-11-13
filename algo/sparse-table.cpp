/* Sparse Table */

/*
    find the queries in O(1)
    precalculates everything in log terms O(nlogn)
    and then gives the result by using the precalculated stuff
*/

struct SparseTable {
    vector<int> a;
    vector<vector<int>> sp;
    int LOG, mxeN;
    SparseTable(int mxeSize) {
        a.resize(mxeSize, 0);
        mxeN = mxeSize;
        LOG = log2(mxeSize) + 1;
        sp.assign(mxeN, vector<int>(LOG, 0));
    }
    void modify(int idx, int val) {
        a[idx] = val;
        sp[idx][0] = val;
    }
    void build() {
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) - 1 < mxeN; i++) {
                sp[i][j] = gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        return gcd(sp[l][k], sp[r - (1 << k) + 1][k]);
    }
};
