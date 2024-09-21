#include "mult_poly.hpp"
#include"utils.hpp"


void test_mult_poly(const std::vector<uint64_t>& p1,
        const std::vector<uint64_t>& p2,
        uint64_t q, uint64_t d
        )
{

    print_results("Input p1", p1);
    print_results("Input p2", p2);
    std::vector<uint64_t> result(p1.size() + p2.size() - 1, 0);
    mult_poly_naive(p1, p2, result);
    print_results("Schoolbook Multiplication", result);

    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q(p1, p2, q,result);
    const std::string q_string = std::to_string(q);
    std::string string_msg = "Wrap around integers modulo a prime number q = " + q_string;
    print_results(string_msg , result);

    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q_cc(p1, p2, q,d, result);
    const std::string d_string = std::to_string(q);
    std::vector<uint64_t> res(result.begin(), result.begin() + std::min(4, static_cast<int>(result.size())));
    string_msg = "Positive wrapped convolution, Cyclic Convolution, cc with q = " +q_string + "  d = " +d_string;
    print_results(string_msg, res);

    std::fill(result.begin(), result.end(), 0);
    mult_poly_naive_q_nwc(p1, p2, q,d, result);
    std::copy_n(result.begin(), d, res.begin());
    string_msg = "Negative wrapped convolution, Cyclic Convolution, cc with q = " +q_string + "  d = " +d_string;
    print_results(string_msg, res);
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
    std::vector<uint64_t> p1 = {1, 2, 3, 4};
    std::vector<uint64_t> p2 = {1, 3, 5, 7};
    test_mult_poly(p1, p2, 17, 4);
    return 0;
}