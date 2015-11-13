/*
 *  Copyright (c) Linas Petkevicius 2015
 *  Vilnius University
 *  GNU General Public license
 * */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/variance.hpp>

#include <iostream>
#include <algorithm>
#include <vector>

#define unlikely(x)    __builtin_expect(static_cast<bool>(x), false)

using namespace boost::accumulators;

namespace Outlier {

struct MeanVar {
    double mean;
    double var;
    int n;

    MeanVar(): mean(0.), var(1.), n(0) {}
    MeanVar(double mu, double s2, int n): mean(mu), var(s2), n(n) {
        check();
    }
    double get_sd() {
        check();
        return sqrt(var*n/(n-1));
    }
    bool check() {
        assert(n > 1);
        assert(var > 1e-40);
    }
};

template< typename T>
void print(std::vector<T>  data) {
    std::cout << "--\n";
    auto print = [](T x) {
        std::cout << " " << x;
    };
    std::for_each(data.begin(), data.end(), print);
    std::cout << "\n";
}

template< typename T>
std::vector<T> permutating(const std::vector<T> & input, \
                           const std::vector<int> &permutation) {
    std::vector<T> m(input.size());
    auto permutate = [input](int x) {
        return input[x];
    };
    std::transform(permutation.begin(), permutation.end(), \
                   m.begin(), permutate);

    return m;
}


template< typename T>
std::vector<int> order(const std::vector<T>& data) {
    std::vector<int> tmp(data.size());
    std::iota(tmp.begin(), tmp.end(), 0);
    auto comparator = [&data](T a, T b) {
        return data[a] < data[b];
    };
    std::sort(tmp.begin(), tmp.end(), comparator);
    return tmp;
}




}  // namespace Outlier

#endif
