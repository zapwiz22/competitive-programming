template<typename S>
struct SegmentTree {
	int n;
	vector<S> tree;

	SegmentTree(int n) : n(n) {
		tree.assign(2 * n, e());
	}

	// identity element
	static S e() {
		return S();   // default identity (user should override by specialization)
	}

	// merge operation
	static S op(const S& a, const S& b) {
		return a + b; // default: sum (user should override)
	}

	void build() {
		for (int i = n - 1; i > 0; --i)
			tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
	}

	void modify(int p, S val) {
		for (tree[p += n] = val; p > 1; p >>= 1)
			tree[p >> 1] = op(tree[p], tree[p ^ 1]);
	}

	S query(int l, int r) {
		S resL = e(), resR = e();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resL = op(resL, tree[l++]);
			if (r & 1) resR = op(tree[--r], resR);
		}
		return op(resL, resR);
	}
};
