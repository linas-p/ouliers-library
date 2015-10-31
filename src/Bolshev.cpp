#include <Bolshev.hpp>

namespace Outlier{
Statistics  Outlier::Bolhsev_method::calculate_statistics(std::vector<double> & data, params & par) {
    std::cout << "Bolshev \n";
    int s = par.s;
    Statistics sta(s);
    std::vector<double> tau = tau_statistics(data);
    std::vector<int> id = order(tau);
    for(int k = 0; k < s; ++k) {
        sta.statistics.push_back( tau[id[k]]/(k+1));
        sta.permutation.push_back( id[k] );
    }

    return sta;
}
}
