#include <gtest/gtest.h>
#include <utils.hpp>
using namespace Outlier;

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

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
