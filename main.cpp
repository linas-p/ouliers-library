/* Copyright 2015
 * Linas Petkevicius
 * Vilnius University
 * GNU General Public License
 * */

#include <calculator.hpp>
#include <Bolshev.hpp>
#include <vector>
#include <utils.hpp>

using namespace Outlier;

params_generate test_smth() {
    params_generate cfg(128, 3, 2, 10.);
    return cfg;
}


int main() {
    params_generate p = test_smth();
    Calculator cal;
    Bolhsev_method *b = new Bolhsev_method;

    int N = 100000;
    std::vector<Statistics> stt;
    stt.reserve(N);
    std::clock_t start = std::clock();
    std::vector<double> sample;
    std::vector<double> tau;
    std::vector<int> id;

    for(int k = 0; k < N; ++k) {
    cal.generate_sample(p.cfg, sample);
    // cal.add_outlier(p, sample);
    cal.normalize(sample);

    tau = tau_statistics(sample);
    //print(tau);
    id = order(tau);
    Statistics st = cal.calculate(b, sample, p.cfg);
    // Statistics<double> st = bolshev_statistics(sample, p.cfg);
    // stt.push_back(st);
    }
    double delta_t = (std::clock() - start)/static_cast<double>(CLOCKS_PER_SEC);
    std::cout << "gen time: " << delta_t <<'\n';
    // std::cout<<"size: "<< stt.size() <<'\n';
    // mediaprint(id);
    //print(st.statistics);
    //print(st.permutation);
    // cal.write_to_file(sample, "nor.csv");

    std::cout << "\n end.";
    return 0;
}

