#include <iostream>
#include "mult_poly.hpp"

void test_mult_poly_naive()
{
    std::vector<uint64_t> a = {1, 2, 3, 4};
    std::vector<uint64_t> b = {1, 3, 5, 7};
    std::vector<uint64_t> result(a.size() + b.size() - 1, 0);
    mult_poly_naive(a, b, result);
    std::cout << "Result of Schoolbook Multiplication: " << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    test_mult_poly_naive();
    return 0;
}