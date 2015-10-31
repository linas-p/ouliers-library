#include <calculator.hpp>

using namespace boost::accumulators;

namespace Outlier{
Calculator::~Calculator() {}
Calculator::Calculator() {}

void Calculator::generate_sample(params & par, std::vector<double> &rez) {
    switch(par.distr) {
    case NORMAL:
        Distribution< boost::normal_distribution<>, double > dis;
        dis.generate_sample(par.n, rez);
        break;
    }
}
void Calculator::calculate_statistic(std::vector<double> & data, criteria_meth met) {

    switch(met) {
    case BOLSHEV:
        break;
    case ROSNER:
        break;
    case HAWKINGS:
        break;
    case BAGPET:
        break;

    }
}


void Calculator::add_outlier(params_generate & par, std::vector<double> &rez) {
    switch(par.cfg.distr) {
    case NORMAL:
        Distribution< boost::normal_distribution<>, double > dis(par.delta);
        dis.generate_outlier(par.r, rez);
        break;
    }
}

double Calculator::rosnerApprox(int n, int s, double alpha, bool two_side) {
    double p = alpha/(n-s+1);
    if(two_side) {
        p /= 2;
    }
    boost::math::students_t stud_t(n-s-1);
    double t = boost::math::quantile(complement(stud_t, p));
    return t*(n-s)/( sqrt((n-s+1)*(n-s-1+pow(t,2))) );
}



void Calculator::normalize(std::vector<double> & data) {
    accumulator_set< double, features<tag::mean, tag::variance > > acc;
    acc = std::for_each( data.begin(), data.end(), acc );
    int n = data.size();
    double mu = mean(acc);
    double sd = sqrt(variance(acc)*n/(n-1));
    for( auto &dat : data) {
        dat = (dat-mu)/sd;
    }

    //std::cout << "Mean:   " << mu << " sd: " << sd << std::endl;

}

void Calculator::write_to_file(std::vector<double>& data, std::string file_name) {

    std::ofstream f(file_name.c_str());
    for(std::vector<double>::const_iterator i = data.begin(); i != data.end(); ++i) {
        f << *i << '\n';
    }
}
}
