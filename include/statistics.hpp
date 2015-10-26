#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <utils.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <vector>

namespace Outlier {

template< typename T>
T Thomson_transform(T& x, unsigned int n, boost::math::students_t &distribution) {
    T result = n * boost::math::cdf(complement(distribution, x*sqrt(n/(n+1-pow(x,2)))));
    return result;
}

template< typename T>
bool Thomson_transform_checking(std::vector<T> data) {
    bool valid = true;
    unsigned int n = data.size();
    for( auto k: data) {
        if( pow(k,2) >= n-1) {
            valid = false;
            throw OutliersException("Data is not normalized!");
        }
    }
    return valid;
}

template< typename T>
std::vector<T> tau_statistics(std::vector<T>& vector, bool check=false) {

    unlikely(check) ? Thomson_transform_checking(vector):0;

    unsigned int n = vector.size();
    unsigned int df = n-2;
    std::vector<T> result(n, 0.);
    boost::math::students_t dist(df);
    int i = 0;
    for( auto &k :vector) {
        result[i] = Thomson_transform(k, df, dist);
        ++i;
    }

    return result;
}


}

#endif
