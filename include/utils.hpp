#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <algorithm>

#define unlikely(x)    __builtin_expect((bool)(x), 0)

namespace Outlier {

struct OutliersException : public std::exception
{
private:
    std::string s;
public:
    OutliersException(std::string ss) : s(ss) {}
    ~OutliersException() throw () {} // Updated
    const char* what() const throw() {
        return s.c_str();
    }
};

template< typename T>
void print(std::vector<T>  data) {
    std::cout << "--\n";
    for( auto &i : data) {
        std::cout << " " << i;
    }
    std::cout << "\n";
}

template< typename T>
std::vector<T> permutating( std::vector<T> & input, std::vector< unsigned int> &permutation) {
    std::vector<T> m(input.size());
    int i = 0;
    for( auto &k :permutation) {
        m[i] = input[k];
        ++i;
    }

    return m;
}

template< typename T>
std::vector<unsigned int> order(std::vector<T>& data) {
    std::vector<unsigned int> tmp(data.size());
    std::iota(tmp.begin(), tmp.end(), 0);
    auto comparator = [&data](T a, T b) {
        return data[a] < data[b];
    };
    std::sort(tmp.begin(), tmp.end(), comparator);
    return tmp;
}

}//end namespace

#endif
