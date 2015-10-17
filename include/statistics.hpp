#ifndef STATISTICS_HPP
#define STATISTICS_HPP
#include <utils.hpp>
#include <params.hpp>
#include <vector>



template< typename T>
T Thomson_transform(T& x, unsigned int n, boost::math::students_t &distribution) {
    T result = n * boost::math::cdf(complement(distribution, x*sqrt(n/(n+1-pow(x,2)))));
    return result;
}


template< typename T>
std::vector<T> tau_statistics(std::vector<T>& vector) {
    /*TODO checking for conditions x^2 < n-1. */
    unsigned int n = vector.size();
    unsigned int df = n-2;
    std::vector<T> result(n, 0.);
    boost::math::students_t dist(df);
    int i = 0;
    for( auto &k :vector) {
        result[i] = Thomson_transform(k, df, dist);
        ++i;
    }

    //std::cout << "\n";
    return result;
}

#endif
