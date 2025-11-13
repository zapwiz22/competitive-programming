/* Fenwick Tree */
struct FenwickTree {
    vector<int> bit;
    FenwickTree(int size) { bit.resize(size + 2, 0); }
    void update(int i, int delta) {
        for (; i < bit.size(); i += (i & (-i))) {
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
