// #include <bits/stdc++.h>
// using namespace std;

// template<typename A, typename B> ostream& operator<<(ostream& os, const
// pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

// template<typename T_container, typename T = typename
// enable_if<!is_same<T_container, string>::value, typename
// T_container::value_type>::type> ostream& operator<<(ostream& os, const
// T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x,
// sep = ", "; return os << '}'; }

// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
// cerr << ' ' << H; dbg_out(T...); }

// #define dbg(...) cerr << "\033[1;31m[" << #__VA_ARGS__ << "] =\033[0m",
// dbg_out(__VA_ARGS__)

// #ifndef DEBUG_H
// #define DEBUG_H

#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define INF INT_MAX
#define INFL LLONG_MAX
// #define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<long, long> pll;

#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(unordered_set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

// #endif
