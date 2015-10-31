#include <statistics.hpp>
#include <vector>

namespace Outlier {

double Thomson_transform(const double x, const int n, boost::math::students_t &distribution) {
    double result = n * boost::math::cdf(complement(distribution, x*sqrt(n/(n+1-pow(x,2)))));
    return result;
}


bool Thomson_transform_checking(const std::vector<double> data) {
    bool valid = true;
    int n = data.size();
    for(auto k: data) {
        if(pow(k,2) >= (n-1)) {
            valid = false;
            //throw OutliersException("Data is not normalized!");
        }
    }
    return valid;
}

std::vector<double> tau_statistics(const std::vector<double> & vector, bool check) {
    unlikely(check) ? Thomson_transform_checking(vector):0;

    int n = vector.size();
    int df = n-2;
    std::vector<double> result(n, 0.);
    boost::math::students_t dist(df);
    int i = 0;
    for(auto &k: vector) {
        result[i] = Thomson_transform(k, df, dist);
        ++i;
    }

    return result;
}
}  // namespace Outlier
