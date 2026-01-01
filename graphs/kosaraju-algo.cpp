/*
 * kosaraju's algorithm - strongly connected components (scc)
 * In a directed graph, strongly connected components (SCCs) are subsets of nodes where every node is
 * reachable from every other node within the same subset
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Step 1: Perform DFS and store nodes in stack by finishing time
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        // Push the node into stack after visiting all neighbors
        st.push(node);
    }

    // Step 2: Perform DFS on transposed graph
    void dfs3(int node, vector<int>& vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components
    int kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Do DFS to fill stack by finishing times
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Build the transpose graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0; // reset visited
            for (auto it : adj[i]) {
                adjT[it].push_back(i); // reverse edge
            }
        }

        // Step 3: Process stack to count SCCs
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<int> adj[n];
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
