#include <bits/stdc++.h>
using namespace std;
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cout << 1 << "\n";
    int n = uid(5, 5);

    // cout << n << " " << m << endl;
    cout << n << endl;

    for (int i = 0; i < n; ++i) {
        cout << uid(-2, 2) << " \n"[i == n - 1];
    }

    // int l = uid(1, n), r = uid(l, n);
    // cout << l << " " << r << endl;

    // for (int i = 0; i < m; ++i) {
    //   cout << uid(1, 10) << " \n"[i == m - 1];
    // }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
//
// int random(int l, int r) {
//     return l + RNG() % (r - l + 1);
// }
//
// int main() {
//     freopen("input.txt", "w", stdout); // Output test case to input.txt
//     ll TESTS = 1;
//     cout << TESTS << "\n";
//
//     while (TESTS--) {
//         ll n = random(2, 5); // Random n in range [1, 1000]
//         cout << n << "\n";
//         ll m = random(2,n);
//         cout << m << endl;
//         // ll k = random(1,n);
//         // cout << m << " " << k << endl;
//         for (ll i = 0; i < m; i++) {
//             cout << random(1,2*n) << " "; // Random array elements in [1,
//             10^9]
//         }
//         cout << "\n";
//     }
// }
