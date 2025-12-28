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
