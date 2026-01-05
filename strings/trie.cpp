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