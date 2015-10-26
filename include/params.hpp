#ifndef PARAMS_HPP
#define PARAMS_HPP

#include <utils.hpp>

namespace Outlier {
enum criteria_meth {

    ROSNER,
    BOLSHEV,
    HAWKINGS,
    BAGPET

};

enum distribution_type {

    NORMAL

};

struct params {
    unsigned int n;
    criteria_meth method;
    distribution_type distr;
    unsigned int s;
    bool two_side;
    params(): method(BAGPET), distr(NORMAL), two_side(true) {}
    bool check() {
        bool params_good = (n > 3 && s< n-2);
        if(!params_good) {
            throw OutliersException("Parameters n and s not initialized! or n < 4! or s > n-1!");
        }
        return params_good;
    }
};

struct params_generate {
    params cfg;
    unsigned int r;
    double delta;
    params_generate(): r(0), delta(0.) {}
    bool check() {
        bool params_good;
        params_good = cfg.check() && (r <= cfg.s);
        if(!params_good) {
            throw OutliersException("Parameter r(outliers number) is set bigger than limit s!");
        }
        return params_good;
    }
};

template< typename T>
struct Statistics {
    std::vector<T> statistics;
    std::vector<unsigned int> permutation;

    Statistics() {}
    Statistics(unsigned int size) {
        statistics.reserve(size);
        permutation.reserve(size);
    }
};
}
#endif
