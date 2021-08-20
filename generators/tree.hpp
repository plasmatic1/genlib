#pragma once
#include "testlib.h"
#include "graph.hpp"

Graph<> randomTreeRooted(int N) {
    Graph<> g(N);
    for (int i = 2; i <= N; i++)
        g.addEdge(rnd.next(1, i-1), i);
    return g;
}

Graph<> weightedTreeRooted(int N, int t) {
    Graph<> g(N);
    for (int i = 2; i <= N; i++)
        g.addEdge(rnd.wnext(1, i-1, t), i);
    return g;
}

Graph<> starGraphRooted(int N) {
    Graph<> g(N);
    for (int i = 2; i <= N; i++)
        g.addEdge(1, i);
    return g;
}

Graph<> lineGraphRooted(int N) {
    Graph<> g(N);
    for (int i = 2; i <= N; i++)
        g.addEdge(i-1, i);
    return g;
}

