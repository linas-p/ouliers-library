#ifndef BOLSHEV_HPP
#define BOLSHEV_HPP

#include <params.hpp>
#include <statistics.hpp>
#include <calculator.hpp>

namespace Outlier {

class Bolhsev_method : public Method{
public:

    Statistics  calculate_statistics(std::vector<double> & data, params & par);

};

}

#endif
