#include <iostream>
#include <iterator>
#include <algorithm>
#include "boost/lambda/lambda.hpp"

int main(){
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::vector<int> nums{3, 4, 1, 3, 5, 2, 15, 199};

    auto print = [](const int& n){
        std::cout << " " << n;
    };

    std::for_each(nums.begin(), nums.end(), print);
    std::for_each(nums.begin(), nums.end(), [](int& n){n++;});

    std::cout << std::endl;
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << std::endl;

    return 0;
}