#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

// Primitive types
void _print(int32_t x) { cerr << x; }
void _print(long x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(unsigned x) { cerr << x; }
void _print(unsigned long x) { cerr << x; }
void _print(unsigned long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(const string &x) { cerr << x; }
void _print(const char *x) { cerr << x; }
void _print(bool x) { cerr << x; }

// Pair
template<typename T1, typename T2>
void _print(const pair<T1, T2> &p) {
    cerr << "{ ";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << " }";
}

// Vector
template<typename T>
void _print(const vector<T> &v) {
    cerr << "[ ";
    for (auto &i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// Set / Multiset
template<typename T>
void _print(const set<T> &s) {
    cerr << "{ ";
    for (auto &i : s) {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}

template<typename T>
void _print(const multiset<T> &s) {
    cerr << "{ ";
    for (auto &i : s) {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}

// Unordered set
template<typename T>
void _print(const unordered_set<T> &s) {
    cerr << "{ ";
    for (auto &i : s) {
        _print(i);
        cerr << " ";
    }
    cerr << "}";
}

// Map
template<typename K, typename V>
void _print(const map<K, V> &m) {
    cerr << "{ ";
    for (auto &p : m) {
        _print(p.first);
        cerr << ": ";
        _print(p.second);
        cerr << " ";
    }
    cerr << "}";
}

template<typename K, typename V>
void _print(const unordered_map<K, V> &m) {
    cerr << "{ ";
    for (auto &p : m) {
        _print(p.first);
        cerr << ": ";
        _print(p.second);
        cerr << " ";
    }
    cerr << "}";
}

// Stack
template<typename T>
void _print(stack<T> st) {
    vector<T> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    _print(v);
}

// Queue
template<typename T>
void _print(queue<T> q) {
    vector<T> v;
    while (!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    _print(v);
}

// Priority queue
template<typename T>
void _print(priority_queue<T> pq) {
    vector<T> v;
    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }
    _print(v);
}

// Debug function
#define debug(...) debug_print(#__VA_ARGS__, __VA_ARGS__)

template<typename... Args>
void debug_print(const char* names, Args&&... args) {
    stringstream ss(names);
    string name;
    vector<string> vnames;

    while (getline(ss, name, ',')) {
        name.erase(0, name.find_first_not_of(" \t"));
        name.erase(name.find_last_not_of(" \t") + 1);
        vnames.push_back(name);
    }

    int32_t i = 0;
    ((cerr << vnames[i++] << " = ", _print(args), cerr << " | "), ...);
    cerr << endl;
}

#endif