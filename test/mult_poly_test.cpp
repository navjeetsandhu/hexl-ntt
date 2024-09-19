#include <iostream>
#include "mult_poly.hpp"

void print_results(const std::string& msg, const std::vector<uint64_t>& result){
    std::cout << msg << std::endl;
    for (uint64_t i : result)
        std::cout << i << ' ';
    std::cout << std::endl;
}


void test_mult_poly()
{
    std::vector<uint64_t> a = {1, 2, 3, 4};
    std::vector<uint64_t> b = {1, 3, 5, 7};
    print_results("Input a", a);
    print_results("Input b", b);
    std::vector<uint64_t> result(a.size() + b.size() - 1, 0);
    mult_poly_naive(a, b, result);
    print_results("Schoolbook Multiplication", result);
    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q(a, b, 17,result);
    print_results("Integers modulo a prime number q = 17", result);
}

int main()
{
    test_mult_poly();
    return 0;
}