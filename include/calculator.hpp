#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <statistics.hpp>
#include <params.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>


namespace Outlier {

struct OutliersException : public std::exception
{
    std::string s;
    OutliersException(std::string ss) : s(ss) {}
    ~OutliersException() throw () {} // Updated
    const char* what() const throw() {
        return s.c_str();
    }
};

template< typename T>
class Method {

public:
    virtual void info() {
        std::cout << "mm\n";
    }

    virtual Statistics<T>  calculate_statistics(std::vector<T> & data, params & par) {
        std::cout << "No method were selected\n";
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
    void func(Method<double> *xyz) {
        xyz->info();
    }

    Statistics<double> calculate(Method<double> *a, std::vector<double> & data, params & par) {
        Statistics<double> tmp =  a->calculate_statistics(data, par);
        return tmp;
    }


private:

};


template<class DIS>
class Distribution
{


    template<class T>
    void generate_vector(T &generator,
                         std::vector<double> &res, unsigned int j = 0)
    {
        for(unsigned int i=j; i<res.size(); ++i)
            res[i]=generator();
    }
    boost::random::mt19937 rng_;
    boost::variate_generator<boost::mt19937&, DIS> generator_;
public:
    Distribution(double mu = 0, double sigma = 1):rng_(), generator_(rng_, DIS(mu, sigma)) {
    };

    void generate_sample(unsigned int n, std::vector<double> &rez) {
        rez.resize(n);
        generate_vector(generator_, rez);
    };
    void generate_outlier(unsigned int r, std::vector<double> &rez) {
        if( r > rez.size()) {
            throw OutliersException("Try adding more outlier than sample size. Try " + std::to_string(r) + " on " +
                                    std::to_string(rez.size()));
        }
        generate_vector(generator_, rez, rez.size()-r);
    };


};
}
#endif
