template <typename T>
struct fenwick {
    int n;
    vector<T> bit;

    fenwick(int n) : n(n), bit(n + 1, T()) {}

    // give 0-based and operations are done 1-based 
    void update(int i, T delta) {
        for (++i; i <= n; i += i & -i) {
            bit[i] = bit[i] + delta;
        }
    }
    T query(int i) {
        T res{};
        for (++i; i > 0; i -= i & -i) {
            res = res + bit[i];
        }
        return res;
    }
};

struct node {
    int a = 0; // don't forget the default value 

    // define the required operations
    inline node operator+(node& x) {
        return node(a - x.a);
    }
    inline bool operator<(node& x) {
        return a < x.a;
    }
};