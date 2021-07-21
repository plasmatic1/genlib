#pragma once
#include <iostream>
using namespace std;

template <typename T> struct IterableSpec {
    T begin, end;
    char delim;

    IterableSpec(T &b, T &e, const char d = ' ') : begin(b), end(e), delim(d) {}
    template <typename U> IterableSpec(const vector<U> v, const char d = ' ') : begin(v.begin()), end(v.end()), delim(d) {}
};
template <typename T> using ispec = IterableSpec<T>; // Alias

template <typename... T> ostream& operator<<(ostream &out, const tuple<T...> v) {
}

template <typename T, typename U> ostream& operator<<(ostream &out, const pair<T, U> v) {
    return out << v.first << ' ' << v.second;
}

template <typename T> ostream& operator<<(ostream &out, const vector<T> v) {
    for (auto i = 0; i < v.size(); i++) {
        if (i > 0) out << ' ';
        out << v[i];
    }
    return out;
}

template <typename T> ostream& operator<<(ostream &out, const IterableSpec<T> its) {
    for (auto it = its.begin; ; ) {
        out << *it;
        if (++it != its.end) out << its.delim;
        else break;
    }
    return out;
}

// Outputting custom types (namely, the graph)
template <typename T> ostream& operator<<(ostream &out, const Graph<T> g) {
    out << g.N() << ' ' << g.M() << '\n';
    for (const auto &e : g.edges())
        out << e << '\n';
    return out;
}
