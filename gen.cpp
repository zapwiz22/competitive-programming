#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#undef int

int main() {
    int tests = 1;
    cout << tests << endl;
    // int n = uid(1, 10);
    int n = 10;
    cout << n << endl;
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);
    random_device rd;
    mt19937 g(rd());
    shuffle(vec.begin(), vec.end(), g);
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

/* how to generate a tree
  print uid(1,i-1) and i
*/

/* how to randomly shuffle a vector
   // Initialize random number generator
    random_device rd;
    mt19937 g(rd());

    // Shuffle the vector
    shuffle(v.begin(), v.end(), g);
*/
