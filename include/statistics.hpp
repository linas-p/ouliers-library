#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <utils.hpp>
#include <boost/math/distributions/students_t.hpp>
#include <vector>

namespace Outlier {

double Thomson_transform(const double x,const int n, boost::math::students_t &distribution);

bool Thomson_transform_checking(const std::vector<double> data);

std::vector<double> tau_statistics(const std::vector<double>& vector, bool check=false);

}

#endif
