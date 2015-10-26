#ifndef DISTRIBUTIONS_HPP
#define DISTRIBUTIONS_HPP

#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <string>

namespace Outlier {

template<class DIS, typename Type>
class Distribution
{
private:
    boost::random::mt19937 rng_;
    boost::variate_generator<boost::mt19937&, DIS> generator_;

public:
    template<class T>
    void generate_vector(T &generator,
                         std::vector<Type> &res, unsigned int j = 0)
    {
        for(unsigned int i=j; i<res.size(); ++i)
            res[i]=generator();
    }

	Distribution(Type mu = 0, Type sigma = 1):rng_(), generator_(rng_, DIS(mu, sigma)) {
    };

    void generate_sample(unsigned int n, std::vector<Type> &rez) {
        rez.resize(n);
        generate_vector(generator_, rez);
    };

    void generate_outlier(unsigned int r, std::vector<Type> &rez) {
        if(unlikely(r > rez.size())) {
            throw OutliersException("Try adding more outlier than sample size. Try " + std::to_string(r) + " on " +
                                    std::to_string(rez.size()));
        }
        generate_vector(generator_, rez, rez.size()-r);
    };


};
}
#endif
