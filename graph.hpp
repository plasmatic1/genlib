#pragma once
#include "testlib.h"
#include "generators/sequence.hpp"
#include <vector>
#include <tuple>
#include <functional>
using namespace std;

struct Unweighted { };

template <typename Weight = Unweighted> class Graph {
private:
    const int _N;
    vector<tuple<int, int, Weight>> _edges;
public:

    Graph(int n) : _N(n), _edges() {}

    const int N() { return _N; }
    const int M() { return _edges.size(); }
    const vector<tuple<int, int, Weight>>& edges() { return _edges; }

    template <typename enable_if<is_same<Weight, Unweighted>::value, Unweighted>::type* = nullptr> void addEdge(int a, int b) {
        _edges.emplace_back(a, b, {});
    }

    void addEdge(int a, int b, Weight w) {
        _edges.emplace_back(a, b, w);
    }

    template <typename T, typename enable_if<is_same<Weight, Unweighted>::value, Unweighted>::type* = nullptr> Graph<T> addWeights(const function<T(int, int)> &weight_f) {
        Graph<T> res(N());
        for (auto [a, b, _] : _edges)
            res.addEdge(a, b, weight_f(a, b));
        return res;
    }

    Graph transpose() {
        Graph res(N());
        for (auto [a, b, w] : _edges)
            res.addEdge(b, a, w);
        return res;
    }

    Graph relabel(vector<int> mapping) {
        Graph res(N());
        for (auto [a, b, w] : _edges)
            res.addEdge(mapping[a-1], mapping[b-1], w);
        return res;
    }

    Graph relabel() {
        return relabel(permutation<int>(_N));
    }

    // mostly, you want to do this with -1 to make it 0-indexed
    // the graph is 1-indexed by default
    Graph shiftNodeLabels(int amount) {
        Graph res(N());
        for (auto [a, b, w] : _edges)
            res.addEdge(a+amount, b+amount, w);
        return res;
    }

    Graph merge(const Graph &o) {
        Graph res(max(_N, o.N()));
        for (auto [a, b, w] : _edges)
            res.addEdge(a, b, w);
        for (auto [a, b, w] : o.edges())
            res.addEdge(a, b, w);
        return res;
    }

    Graph shuffleEdges() {
        Graph res(N());
        auto clone = _edges;
        shuffle(clone.begin(), clone.end());
        for (auto [a, b, w] : clone)
            res.addEdge(a, b, w);
        return res;
    }
};