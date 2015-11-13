/*
 *  Copyright (c) Linas Petkevicius 2015
 *  Vilnius University
 *  GNU General Public license
 * */

#ifndef HAWKINGS_HPP
#define HAWKINGS_HPP

#include <Outlier/params.hpp>
#include <Outlier/statistics.hpp>
#include <Outlier/calculator.hpp>
#include <vector>

namespace Outlier {

class Hawkings_method : public Method {
public:
    Statistics calculate_statistics(std::vector<double> * data, \
                                     const params & par);
};

}  // namespace Outlier

#endif
