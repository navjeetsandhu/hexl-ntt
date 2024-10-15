#include "mult_poly.hpp"
#include "mult_fft.hpp"
#include"utils.hpp"

#define N_FFT_TEST 4

void test_mult_fft(const std::array<uint64_t, N_FFT_TEST>& p1, const std::array<uint64_t, N_FFT_TEST>& p2)
{

    std::string string_msg = "Naive Multiplication";
    print_results<uint64_t>("Input p1", p1.data(), p1.size());
    print_results<uint64_t>("Input p1", p1.data(), p1.size());
    std::array<uint64_t, N_FFT_TEST> result = {0,0,0,0};
    PolyMulNaive(result, p1, p2);
    print_results<uint64_t>(string_msg, result.data(), result.size());


    std::fill(result.begin(), result.end(), 0);
    PolyMulNaive(result, p1, p2);
    string_msg = "FFT Multiplication";
    print_results<uint64_t>(string_msg, result.data(), result.size());
}


int main()
{
    // make sure set N_FFT to 4 before testing
    std::array<uint64_t,  N_FFT_TEST> p1 = {1, 2, 3, 4};
    std::array<uint64_t,  N_FFT_TEST> p2 = {1, 3, 5, 7};
    test_mult_fft(p1, p2);
    p2 = {5, 6, 7, 8};
    test_mult_fft(p1, p2);
    return 0;
}