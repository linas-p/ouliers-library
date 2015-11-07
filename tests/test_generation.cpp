/* Copyright 2015
 * Linas Petkevicius
 * Vilnius University
 * GNU General Public License
 * */

#include <gtest/gtest.h>

#include <utils.hpp>
#include <params.hpp>
#include <calculator.hpp>
#include <Bolshev.hpp>

#include <vector>
#include <string>

using Outlier::params;
using Outlier::print;
using Outlier::order;
using Outlier::permutating;
using Outlier::Thomson_transform_checking;

TEST(params, initialisaton) {
    params p(20, 3), p1(3, 1);
    EXPECT_EQ(p.check(), true);
    EXPECT_EQ(p1.check(), false);
}


TEST(print, print_usage) {
    std::vector<int> v, v2 = {-4};
    print(v);
    print(v2);
    std::vector<std::string> s, s1 = {"a", "b", "c"};
    print<std::string>(s);
    print<std::string>(s1);
}

TEST(order, ordering) {
    std::vector<int> v, v1 = {3,1,2,-2};
    std::vector<double> w = {3., 1., 2., -2.};

    print(order(v));
    print(order(v1));
    print(order(w));
}

TEST(permutating, permutations) {
    std::vector<int> w, v= {3, 1, 2, -2};
    std::vector<int> o;
    o = order(v);
    print(v);
    print(order(v));
    w = permutating(v, o);
    print(w);
}

TEST(Thomson_transform_checking, usage) {

    std::vector<double> p = {1,1,1,1}, p1 = {1,1,1,10}, p2;
    EXPECT_EQ(Thomson_transform_checking(p), true);
    EXPECT_EQ(Thomson_transform_checking(p1), false);
    EXPECT_EQ(Thomson_transform_checking(p2), false);

}


/*
TEST(main, all) {

	params par;
    par.n = 128;
    par.s = 3;
    params_generate p;
    p.cfg = par;
    p.r = 2;
    p.delta = 10;


	Calculator cal;
    Bolhsev_method<double> *b = new Bolhsev_method<double>;

    int N = 10000;
    std::vector<Statistics<double>> stt;
    stt.reserve(N);
    std::clock_t start = std::clock();
    std::vector<double> sample;
    std::vector<double> tau;
    std::vector<int> id;

	//    for(int k = 0; k < N; ++k) {
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
    print(st.statistics);
    print(st.permutation);



}*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
