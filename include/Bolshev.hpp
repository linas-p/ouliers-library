#ifndef BOLSHEV_HPP
#define BOLSHEV_HPP

#include <params.hpp>
#include <statistics.hpp>
#include <calculator.hpp>

namespace Outlier {

template< typename T>
class Bolhsev_method : public Method<T> {
public:

    Statistics<T>  calculate_statistics(std::vector<T> & data, params & par) {
        std::cout << "Bolshev \n";
        unsigned int s = par.s;
        Statistics<T> sta(s);
        std::vector<T> tau = tau_statistics<T>(data);
        std::vector<unsigned int> id = order<T>(tau);
        for(unsigned int k = 0; k < s; ++k) {
            sta.statistics.push_back( tau[id[k]]/(k+1));
            sta.permutation.push_back( id[k] );
        }

        return sta;
    }

};

}

#endif
