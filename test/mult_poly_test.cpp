#include <iostream>
#include "mult_poly.hpp"

void print_results(const std::string& msg, const std::vector<uint64_t>& result){
    std::cout << msg << ": " << std::endl;
    for (uint64_t i : result)
        std::cout << i << ' ';
    std::cout << std::endl << std::endl;
}


void test_mult_poly_one()
{
    std::vector<uint64_t> p1 = {1, 2, 3, 4};
    std::vector<uint64_t> p2 = {1, 3, 5, 7};
    print_results("Input p1", p1);
    print_results("Input p2", p2);
    std::vector<uint64_t> result(p1.size() + p2.size() - 1, 0);
    mult_poly_naive(p1, p2, result);
    print_results("Schoolbook Multiplication", result);

    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q(p1, p2, 17,result);
    print_results("Wrap around integers modulo a prime number q = 17", result);

    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q_cc(p1, p2, 17,4, result);
    std::vector<uint64_t> res(result.begin(), result.begin() + std::min(4, static_cast<int>(result.size())));
    print_results("Cyclic Convolution (CC) q = 17 d =4 ", res);

    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q_nwc(p1, p2, 17,4, result);
    std::copy_n(result.begin(), 4, res.begin());
    //std::vector<uint64_t> res1(result.begin(), result.begin() + std::min(4, static_cast<int>(result.size())));
    print_results("Negative wrapped convolution (negacyclic convolution):  q = 17 d =4 ", result);
    print_results("Negative wrapped convolution (negacyclic convolution):  q = 17 d =4 ", res);
}


void test_mult_poly_one_nwc()
{
    std::vector<uint64_t> p1 = {1, 2, 3, 4};
    std::vector<uint64_t> p2 = {1, 3, 5, 7};
    print_results("Input p1", p1);
    print_results("Input p2", p2);
    std::vector<uint64_t> result(p1.size() + p2.size() - 1, 0);

    mult_poly_naive_q_nwc(p1, p2, 17,4, result);
    std::vector<uint64_t> res(result.begin(), result.begin() + std::min(4, static_cast<int>(result.size())));
    print_results("Negative wrapped convolution (negacyclic convolution):  q = 17 d =4 ", result);
    print_results("Negative wrapped convolution (negacyclic convolution):  q = 17 d =4 ", res);
}

void test_mult_poly_two() {
    std::vector<uint64_t> p1 = {1, 2, 3, 4};
    std::vector<uint64_t> p2 = {5, 6, 7, 8};
    print_results("Input p1", p1);
    print_results("Input p2", p2);
    std::vector<uint64_t> result(p1.size() + p2.size() - 1, 0);
    mult_poly_naive(p1, p2, result);
    print_results("Schoolbook Multiplication", result);
}


int main()
{
    test_mult_poly_one_nwc();
    return 0;
}