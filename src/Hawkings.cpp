/* Copyright 2015
 * Linas Petkevicius
 * Vilnius University
 * GNU General Public License
 * */
 #include <Outlier/Hawkings.hpp>
#include <Outlier/utils.hpp>

namespace Outlier {
Statistics Outlier::Hawkings_method::calculate_statistics(std::vector<double>* \
        data, const params & par) {
    //  std::cout << "Hawkings_method \n";
    int s = par.s;
    int n = par.n;
    MeanVar m = get_mean(data);
    std::vector<int> o = order(*data);
    std::vector<double> b(s);
    auto x = [data, mu=m.mean, sd=m.get_sd(), n](int i) {
        return (data->at(i)-mu)/sd;
    };

    for (int k = 1; k < s; ++k) {
    	b.resize(k);
        std::transform(o.end()-k, o.end()-1, b.begin(), x);
        b[k-1] = 1/sqrt(k*(n-k)) * std::accumulate(b.begin(), b.end(), 0);
        b.clear();
    }

    Statistics sta(s);
    return sta;
}
}  // namespace Outlier
