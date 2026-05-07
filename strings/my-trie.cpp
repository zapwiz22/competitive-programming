struct Trie {
    static constexpr int letters = 26;
    struct Node {
        vector<int> next_node;
        int is_a_leaf = 0;
        Node() {
            next_node.assign(letters, -1);
        }
    };

    vector<Node> trie_tree;
    Trie() {
        trie_tree.emplace_back();
    }
    void add_string(string& a) {
        int root_here = 0;
        for (char c : a) {
            int index = c - 'a';
            if (trie_tree[root_here].next_node[index] == -1) {
                trie_tree[root_here].next_node[index] = (int)trie_tree.size();
                trie_tree.emplace_back();
            }
            root_here = trie_tree[root_here].next_node[index];
        }
        trie_tree[root_here].is_a_leaf++;
    }
};