#include <gtest/gtest.h>
#include <utils.hpp>
#include <params.hpp>
#include <calculator.hpp>
#include <Bolshev.hpp>

using namespace Outlier;

TEST(params, initialisaton){

	params p, p1, p2, p3;
	p.n = 20;
	p.s = 3;
//	EXPECT_EQ(p.check(), true);
	p1.n = 3;
	p1.s = 1;
	//p1.check();


}


TEST(print, printing) {

    std::vector<int> v;
    print(v);
    v.push_back(-1);
    print(v);
    std::vector<std::string> s;
    print(s);
    s.push_back( "test a" );
    print(s);

}

TEST(order, ordering) {

    std::vector<int> v;
    std::vector<double> w;

    v.push_back( 3 );
    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( -2 );
    print( order(v) );


    w.push_back(3.);
    w.push_back(1.);
    w.push_back(2.);
    w.push_back(-2.);
    print(order(w));

}

TEST(permutating, permutations) {

    std::vector<int> v, w;
    std::vector<unsigned int> o;
    v.push_back( 3 );
    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( -2 );
    o = order(v);
    print( v );
    print( order(v) );
    w = permutating(v, o);
    print( w );
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
    print(st.statistics);
    print(st.permutation);



}*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
