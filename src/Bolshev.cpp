/* Copyright 2015
 * Linas Petkevicius
 * Vilnius University
 * GNU General Public License
 * */
#include <Outlier/Bolshev.hpp>

namespace Outlier {
Statistics  Outlier::Bolhsev_method::calculate_statistics(std::vector<double>* \
        data, const params & par) {
    //  std::cout << "Bolshev \n";
    int s = par.s;
    Statistics sta(s);
    std::vector<double> tau = tau_statistics(data);
    std::vector<int> id = order(tau);
    for (int k = 0; k < s; ++k) {
        sta.push_back(tau[id[k]]/(k+1), id[k]);
    }

    return sta;
}
}  // namespace Outlier
