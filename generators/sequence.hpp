#pragma once
#include "../testlib.h"
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> vector<T> permutation(int len) {
    vector<T> res(len);
    iota(res.begin(), res.end(), 1);
    shuffle(res.begin(), res.end());  // Make sure it uses testlib.h!!!
    return res;
}

template <typename T> vector<T> permutation(int len, int numSwaps) {
    vector<T> res(len);
    iota(res.begin(), res.end(), 1);
    for (auto i = 0; i < numSwaps; i++)
        swap(res[rnd.next(0, res.size()-1)], res[rnd.next(0, res.size()-1)]);
    return res;
}

template <typename T> vector<T> sequenceWithSum(int len, T sum, int atLeast) {
    vector<T> res(len, atLeast);
    sum -= len * atLeast;
    vector<T> p{0};
    for (auto i = 0; i < len-1; i++)
        p.push_back(rnd.next((T)0, sum));
    p.push_back(sum);
    sort(p.begin(), p.end());
    for (auto i = 0; i < len; i++)
        res[i] += p[i+1] - p[i];
    return res;
}
