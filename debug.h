#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

// Forward declarations for all _print functions
void _print(int x);
void _print(long x);
void _print(long long x);
void _print(unsigned x);
void _print(unsigned long x);
void _print(unsigned long long x);
void _print(float x);
void _print(double x);
void _print(long double x);
void _print(char x);
void _print(const char* x);
void _print(const string& x);
void _print(bool x);

template<typename T1, typename T2>
void _print(const pair<T1, T2>& p);

template<typename T>
void _print(const vector<T>& v);

template<typename T>
void _print(const set<T>& s);

template<typename T>
void _print(const unordered_set<T>& s);

template<typename T>
void _print(const multiset<T>& s);

template<typename K, typename V>
void _print(const map<K, V>& m);

template<typename K, typename V>
void _print(const unordered_map<K, V>& m);

template<typename T, size_t N>
void _print(const array<T, N>& arr);

template<typename T>
void _print(const deque<T>& dq);

template<typename T>
void _print(stack<T> st);

template<typename T>
void _print(queue<T> q);

template<typename T>
void _print(priority_queue<T> pq);

template<typename T>
void _print(priority_queue<T, vector<T>, greater<T>> pq);

template<typename T>
void _print(const list<T>& lst);

template<typename T>
void _print(const forward_list<T>& flst);

template<size_t N>
void _print(const bitset<N>& bs);

template<typename... Args>
void _print(const tuple<Args...>& t);

template<typename T>
void _print(const complex<T>& c);

// Core type printers implementation
void _print(int x) { cerr << x; }
void _print(long x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(unsigned x) { cerr << x; }
void _print(unsigned long x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(const char* x) { cerr << '\"' << x << '\"'; }
void _print(const string& x) { cerr << '\"' << x << '\"'; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

// Pair
template<typename T1, typename T2>
void _print(const pair<T1, T2>& p) {
    cerr << '{';
    _print(p.first);
    cerr << ',';
    _print(p.second);
    cerr << '}';
}

// Vector
template<typename T>
void _print(const vector<T>& v) {
    cerr << '[';
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) cerr << ',';
        _print(v[i]);
    }
    cerr << ']';
}

// Set
template<typename T>
void _print(const set<T>& s) {
    cerr << '{';
    for (auto it = s.begin(); it != s.end();) {
        _print(*it);
        if (++it != s.end()) cerr << ',';
    }
    cerr << '}';
}

// Unordered Set
template<typename T>
void _print(const unordered_set<T>& s) {
    cerr << '{';
    for (auto it = s.begin(); it != s.end();) {
        _print(*it);
        if (++it != s.end()) cerr << ',';
    }
    cerr << '}';
}

// Multiset
template<typename T>
void _print(const multiset<T>& s) {
    cerr << '{';
    for (auto it = s.begin(); it != s.end();) {
        _print(*it);
        if (++it != s.end()) cerr << ',';
    }
    cerr << '}';
}

// Map
template<typename K, typename V>
void _print(const map<K, V>& m) {
    cerr << '{';
    for (auto it = m.begin(); it != m.end();) {
        _print(it->first);
        cerr << ':';
        _print(it->second);
        if (++it != m.end()) cerr << ',';
    }
    cerr << '}';
}

// Unordered Map
template<typename K, typename V>
void _print(const unordered_map<K, V>& m) {
    cerr << '{';
    for (auto it = m.begin(); it != m.end();) {
        _print(it->first);
        cerr << ':';
        _print(it->second);
        if (++it != m.end()) cerr << ',';
    }
    cerr << '}';
}

// Array
template<typename T, size_t N>
void _print(const array<T, N>& arr) {
    cerr << '[';
    for (size_t i = 0; i < N; i++) {
        if (i > 0) cerr << ',';
        _print(arr[i]);
    }
    cerr << ']';
}

// Deque
template<typename T>
void _print(const deque<T>& dq) {
    cerr << '[';
    for (size_t i = 0; i < dq.size(); i++) {
        if (i > 0) cerr << ',';
        _print(dq[i]);
    }
    cerr << ']';
}

// Stack
template<typename T>
void _print(stack<T> st) {
    vector<T> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(), temp.end());
    cerr << "stack:";
    _print(temp);
}

// Queue
template<typename T>
void _print(queue<T> q) {
    vector<T> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    cerr << "queue:";
    _print(temp);
}

// Priority Queue (max heap)
template<typename T>
void _print(priority_queue<T> pq) {
    vector<T> temp;
    while (!pq.empty()) {
        temp.push_back(pq.top());
        pq.pop();
    }
    cerr << "max_heap:";
    _print(temp);
}

// Priority Queue (min heap)
template<typename T>
void _print(priority_queue<T, vector<T>, greater<T>> pq) {
    vector<T> temp;
    while (!pq.empty()) {
        temp.push_back(pq.top());
        pq.pop();
    }
    cerr << "min_heap:";
    _print(temp);
}

// List
template<typename T>
void _print(const list<T>& lst) {
    cerr << '[';
    for (auto it = lst.begin(); it != lst.end();) {
        _print(*it);
        if (++it != lst.end()) cerr << ',';
    }
    cerr << ']';
}

// Forward List
template<typename T>
void _print(const forward_list<T>& flst) {
    cerr << '[';
    for (auto it = flst.begin(); it != flst.end();) {
        _print(*it);
        if (++it != flst.end()) cerr << ',';
    }
    cerr << ']';
}

// Bitset
template<size_t N>
void _print(const bitset<N>& bs) {
    cerr << "bitset:\"";
    for (size_t i = 0; i < N; i++) {
        cerr << (bs.test(i) ? '1' : '0');
    }
    cerr << "\"";
}

// Tuple
template<typename Tuple, size_t... Is>
void _print_tuple(const Tuple& t, index_sequence<Is...>) {
    cerr << '(';
    (..., (cerr << (Is == 0 ? "" : ","), _print(get<Is>(t))));
    cerr << ')';
}

template<typename... Args>
void _print(const tuple<Args...>& t) {
    _print_tuple(t, index_sequence_for<Args...>{});
}

// Complex
template<typename T>
void _print(const complex<T>& c) {
    cerr << c.real();
    if (c.imag() >= 0) cerr << '+';
    cerr << c.imag() << 'i';
}

// Main debug function
#define debug(...) debug_print(#__VA_ARGS__, __VA_ARGS__)

template<typename... Args>
void debug_print(const char* names, Args&&... args) {
    cerr << "\033[1;36m";
    stringstream ss(names);
    string name;
    vector<string> vnames;
    
    // Parse variable names
    while (getline(ss, name, ',')) {
        name.erase(0, name.find_first_not_of(" \t\n\r\f\v"));
        name.erase(name.find_last_not_of(" \t\n\r\f\v") + 1);
        vnames.push_back(name);
    }
    
    // Print each variable with its name
    int i = 0;
    ((cerr << (i++ ? " | " : "") << vnames[i-1] << " = ", _print(args)), ...);
    cerr << "\033[0m" << endl;
}

#endif // DEBUG_H