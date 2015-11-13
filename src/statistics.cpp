/* Copyright 2015
 * Linas Petkevicius
 * Vilnius University
 * GNU General Public License
 * */
 #include <Outlier/statistics.hpp>
#include <vector>
#include <algorithm>

namespace Outlier {

double Thomson_transform(const double x, const int n,  \
                         const boost::math::students_t &distribution) {
    double result = n * boost::math::cdf(complement(distribution, \
                                         x*sqrt(n/(n+1-pow(x, 2)))));
    return result;
}


bool Thomson_transform_checking(const std::vector<double> *data) {
    if ( data->size() == 0 ) {
        return false;
    }

    auto is_positive = [](double const k, int const n) {
        return (n > pow(k, 2)+1);
    };
    return std::all_of(data->begin(), data->end(), std::bind(is_positive, \
                       std::placeholders::_1, data->size()));
}

std::vector<double> tau_statistics(const std::vector<double> * vector, \
                                   bool check) {
    unlikely(check) ? Thomson_transform_checking(vector):0;

    int n = vector->size();
    int df = n-2;
    std::vector<double> result(n, 0.);
    boost::math::students_t dist(df);
    std::transform(vector->begin(), vector->end(), result.begin(), \
                   std::bind(Thomson_transform, std::placeholders::_1, \
                             df, dist));

    return result;
}
}  // namespace Outlier
