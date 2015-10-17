#ifndef BOLSHEV_HPP
#define BOLSHEV_HPP

#include <params.hpp>
#include <statistics.hpp>

template< typename T>
Statistics<T>  bolshev_statistics(std::vector<T> & data, params & par) {
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


#endif
