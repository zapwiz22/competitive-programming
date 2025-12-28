#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1000000007, mod1 = 998244353, inf = 1e18;
const int N = 1e3 + 1;

/*
    https://leetcode.com/contest/weekly-contest-478/problems/minimum-operations-to-equalize-subarrays/
*/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> rems(n);
        rems[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] % k == nums[i - 1] % k) {
                rems[i] = rems[i - 1];
            } else {
                rems[i] = i;
            }
        }

        // for (int i=0;i<n;i++) {
        //     cerr << rems[i] << " ";
        // }
        // cerr << endl;

        /* Mo's Algorithm */
        int BLK = 200;
        vector<array<int, 3>> Q;
        int m = queries.size();
        vector<long long> ans(m);
        for (int i = 0; i < m; i++) {
            Q.push_back({queries[i][0],queries[i][1],i});
        }
        sort(Q.begin(), Q.end(), [&](auto& a, auto& b) {
            if (a[0] / BLK != b[0] / BLK) return (a[0] / BLK) < (b[0] / BLK);
            else return a[1] < b[1];
        });
        multiset<int> s1, s2;
        long long sum1 = 0, sum2 = 0;
        auto balance = [&]() {
            while (s1.size() > s2.size()) {
                auto it = prev(s1.end());
                sum1 -= *it, sum2 += *it;
                s2.insert(*it), s1.erase(it);
            }
            while (s1.size() < s2.size()) {
                auto it = s2.begin();
                sum1 += *it, sum2 -= *it;
                s1.insert(*it), s2.erase(it);
            }
        };
        auto add = [&](int x) {
            if (s1.size() == 0) s1.insert(x), sum1 += x;
            else if ((*s1.rbegin()) >= x) s1.insert(x), sum1 += x;
            else s2.insert(x), sum2 += x;
            balance();
        };
        auto del = [&](int x) {
            auto it = s1.find(x);
            if (it != s1.end()) s1.erase(it), sum1 -= x;
            else {
                it = s2.find(x);
                s2.erase(it), sum2 -= x;
            }
            balance();
        };
        auto get = [&]() {
            // for this question the operations required 
            // to make every number equal to the median 
            long long median = *s1.rbegin();
            long long diff = median * s1.size() - sum1 + sum2 - median * s2.size();
            return diff / k;
        };
        int left = 0, right = 0;
        for (auto& [l, r, idx] : Q) {
            if (rems[r] > rems[l]) {
                ans[idx] = -1;
            } else {
                while (left > l) add(nums[--left]);
                while (right < r + 1) add(nums[right++]);
                while (left < l) del(nums[left++]);
                while (right > r + 1) del(nums[--right]);
                ans[idx] = get();
            }

            // cerr << l << " " << r << endl;
            // for (auto val:s1) cerr << val << " ";
            // cerr << endl;
            // for (auto val:s2) cerr << val << " ";
            // cerr << endl;
        }

        return ans;
    }
};

void solve() {
    vector<vector<int>> queries = {{0,1},{0,2}};
    vector<int> nums = {1,4,7};
    int k = 3;
    Solution sol;
    vector<int> ans = sol.minOperations(nums, k, queries);
    for (auto v : ans) {
        cout << v << " ";
    }
    cout << endl;
}

#undef int

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) {
        cerr << "Case #" << i << ": " << endl;
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}