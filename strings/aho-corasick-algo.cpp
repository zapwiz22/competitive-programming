#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod = 998244353;

/* Aho-Corasick Algorithm */
const int MAX_N = 6e5;
const int SIGMA = 26;

// The number of nodes in trie
int nodes = 1;
int trie[MAX_N][SIGMA];
int fail[MAX_N];  // fail[u] = the failure link for node
int seen[MAX_N];  // check if a node has been visited in trie
int ans[MAX_N];   // ans[i] = the number of occurrences of word i
int cover[MAX_N];

// leaf[node] stores the indices of the words ending in node
vector<int> leaf[MAX_N];
vector<int> g[MAX_N];

/** Add a word to the trie */
void add_word(const string &word, const int &idx) {
	int node = 1;
	for (char ch : word) {
		if (trie[node][ch - 'a'] == 0) { trie[node][ch - 'a'] = ++nodes; }
		node = trie[node][ch - 'a'];
	}
	leaf[node].push_back(idx);
    cover[node] |= (1ll << idx);
}

/** BFS to building the failure and suffix links */
void build() {
	queue<int> q;
	int node = 1;
	fail[node] = 1;
	for (int i = 0; i < SIGMA; i++) {
		if (trie[node][i]) {
			fail[trie[node][i]] = node;
			q.push(trie[node][i]);
		} else {
			trie[node][i] = 1;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
        cover[node] |= cover[fail[node]];
		for (int i = 0; i < SIGMA; i++) {
			if (trie[node][i]) {
				fail[trie[node][i]] = trie[fail[node]][i];
				q.push(trie[node][i]);
			} else {
				trie[node][i] = trie[fail[node]][i];
			}
		}
	}
	for (int i = 2; i <= nodes; i++) { g[fail[i]].push_back(i); }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, l;
    string s;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> s;
        add_word(s, i);
    }
    build();

    int dp[l + 1][nodes + 1][(1ll << n)] = {};
    dp[0][1][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 1; j <= nodes; j++) {
            for (int mask = 0; mask < (1ll << n); mask++) {
                int cur = dp[i][j][mask];
                if (cur == 0) continue;

                for (int c = 0; c < 26; c++) {
                    int nxt = trie[j][c];
                    int nmask = mask | cover[nxt];

                    dp[i + 1][nxt][nmask] = (dp[i + 1][nxt][nmask] + cur) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= nodes; i++) {
        ans = (ans + dp[l][i][(1ll << n) - 1]) % mod;
    }
    cout << ans << endl;
    return 0;
}