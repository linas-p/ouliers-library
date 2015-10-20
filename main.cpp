#include <utils.hpp>
#include <params.hpp>
#include <statistics.hpp>
#include <calculator.hpp>
#include <Bolshev.hpp>

using namespace std;
using namespace Outlier;

params_generate test_smth() {

    params par;
    par.n = 128;
    par.s = 3;
    params_generate cfg;
    cfg.cfg = par;
    cfg.r = 2;
    cfg.delta = 10;
    return cfg;
}


int main()
{
    params_generate p = test_smth();
    Calculator cal;
    Method<double> *a = new Method<double>;
    Bolhsev_method<double> *b = new Bolhsev_method<double>;
    //a->info();
    //b->info();
    //cal.func(a);
    //cal.func(b);


    unsigned int N = 10000;
    std::vector<Statistics<double>> stt;
    stt.reserve(N);
    std::clock_t start = std::clock();
    std::vector<double> sample;
    std::vector<double> tau;
    std::vector<unsigned int> id;

//    for(unsigned int k = 0; k < N; ++k) {
    cal.generate_sample(p.cfg, sample);
    //cal.add_outlier(p, sample);
    cal.normalize(sample);

    tau = tau_statistics(sample);
    print(tau);
    id = order<double>(tau);
	Statistics<double> st = cal.calculate(b, sample, p.cfg);
    //Statistics<double> st = bolshev_statistics(sample, p.cfg);
    //stt.push_back(st);
    // }

    std::cout<<"gen time: "<< ( std::clock() - start ) / (double) CLOCKS_PER_SEC <<'\n';
    //std::cout<<"size: "<< stt.size() <<'\n';
    //mediaprint(id);
    //print(st.statistics);
    //print(st.permutation);
    //cal.write_to_file(sample, "nor.csv");

    std::cout << "\n end.";
    return 0;
}

