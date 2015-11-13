/*
 *  Copyright (c) Linas Petkevicius 2015
 *  Vilnius University
 *  GNU General Public license
 * */

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <Outlier/params.hpp>
#include <Outlier/statistics.hpp>
#include <Outlier/distributions.hpp>

#include <boost/random/normal_distribution.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

namespace Outlier {

MeanVar get_mean(std::vector<double> * data, int = 0);

class Method {
public:
    virtual Statistics  calculate_statistics(std::vector<double> * data, \
            const params & par) {
        Statistics tmp;
        //  throw OutliersException("No method were selected
        //  to calculate statistics\n");
        return tmp;
    }
};


class Calculator {
public:
    Calculator();
    ~Calculator();
    void generate_sample(const params &, std::vector<double> *);
    void calculate_statistic(std::vector<double> * data, \
                             const criteria_meth met = BOLSHEV);

    void add_outlier(const params_generate &, std::vector<double> *);

    void normalize(std::vector<double>&);

    void write_to_file(std::vector<double> &, std::string);
    double rosnerApprox(int n, int s, double alpha = 0.05, \
                        bool two_side = true);

    Statistics calculate(Method *a, std::vector<double> * data, \
                         const params & par) {
        Statistics tmp =  a->calculate_statistics(data, par);
        return tmp;
    }
};

}  // namespace Outlier
#endif
