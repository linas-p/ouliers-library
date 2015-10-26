#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <params.hpp>
#include <statistics.hpp>
#include <distributions.hpp>

#include <boost/random/normal_distribution.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <fstream>
#include <iterator>

namespace Outlier {



template< typename T>
class Method {

public:

    virtual Statistics<T>  calculate_statistics(std::vector<T> & data, params & par) {
        throw OutliersException("No method were selected to calculate statistics\n");
    }
};


class Calculator {

public:
    Calculator();
    ~Calculator();
    void generate_sample(params &, std::vector<double> &);
    void calculate_statistic(std::vector<double> & data, criteria_meth met = BOLSHEV);

    void add_outlier(params_generate &, std::vector<double> &);

    void normalize(std::vector<double>&);

    void write_to_file(std::vector<double> &, std::string);
    double rosnerApprox(unsigned int n, unsigned int s, double alpha=0.05, bool two_side=true);

    Statistics<double> calculate(Method<double> *a, std::vector<double> & data, params & par) {
        Statistics<double> tmp =  a->calculate_statistics(data, par);
        return tmp;
    }


private:

};

}
#endif
