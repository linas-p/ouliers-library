/*
 *  Copyright (c) Linas Petkevicius 2015
 *  Vilnius University
 *  GNU General Public license
 * */

#ifndef PARAMS_HPP
#define PARAMS_HPP

#include <Outlier/utils.hpp>
#include <vector>

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
    int n;
    criteria_meth method;
    distribution_type distr;
    int s;
    bool two_side;
    params(int _n, int _s): n(_n), method(BAGPET), distr(NORMAL), \
        s(_s), two_side(true) {}
    bool check() {
        bool params_good = (n > 3 && s< n-2);
        if (!params_good) {
            //  throw OutliersException("Parameters n and s not initialized!
            //  or n < 4! or s > n-1!");
        }
        return params_good;
    }
};

struct params_generate {
    params cfg;
    int r;
    double delta;
    params_generate(int n, int s, int r, double d): cfg(n, s), r(r), delta(d) {}
    bool check() {
        bool params_good;
        params_good = cfg.check() && (r <= cfg.s);
        if (!params_good) {
            //  throw OutliersException("Parameter r(outliers number)
            //  is set bigger than limit s!");
        }
        return params_good;
    }
};

struct Statistics {
    std::vector<double> statistics;
    std::vector<int> permutation;

    Statistics() {}
    explicit Statistics(int size) {
        statistics.reserve(size);
        permutation.reserve(size);
    }
    ~Statistics() {
        statistics.clear();
        permutation.clear();
    }
    void push_back(double t, int id) {
        statistics.push_back(t);
        permutation.push_back(id);
    }
};
}  // namespace Outlier
#endif
