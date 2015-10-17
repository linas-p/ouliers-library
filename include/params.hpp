#ifndef PARAMS_HPP
#define PARAMS_HPP
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/students_t.hpp>

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
};


struct params_generate {
    params cfg;
    unsigned int r;
    double delta;
    params_generate(): r(0.), delta(0.) {}
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

#endif
