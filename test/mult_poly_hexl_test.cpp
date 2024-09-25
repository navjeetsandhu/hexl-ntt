#include<iostream>
#include "ntt.hpp"
#include "custom_assert.h"
#include"utils.hpp"

void print_input(const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus) {
    std::cout << "mod " << modulus << std::endl;
    print_results("p1", p1, degree);
    print_results("p2", p2, degree);
}

void print_verify_output(const uint64_t *result, const uint64_t *output, uint64_t degree) {
    print_results("actual output", output, degree);
    print_results("expected result", result, degree);

    for(uint64_t i=0;i<degree;i++){
        c_assert(result[i] == output[i]);
    }
    std::cout << "Test Pass" << "\n \n \n";
}

void test_eltwise_mult_mod(const uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus) {
    std::cout << "test_eltwise_mult_mod with degree: " << degree << std::endl;
    print_input(p1, p2, degree, modulus);
    std::vector<uint64_t> output(degree);

    ntt::eltwise_mult_mod(output.data(), p1, p2, degree, modulus);
    print_verify_output(result, output.data(), degree);
}

void test_eltwise_mult_mod() {
    std::vector<uint64_t> p1 = {10, 913, 7679, 6764};
    std::vector<uint64_t> p2 = {26, 913, 7679, 6764};
    std::vector<uint64_t> result = {260, 4021, 4, 3660};
    test_eltwise_mult_mod(result.data(), p1.data(), p2.data(), 4, 7681);
}


void test_ntt_nwc(const uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus) {
    std::cout << "test_ntt_nwc with degree: " << degree << std::endl;
    print_input(p1, p2, degree, modulus);
    std::vector<uint64_t> output(degree);

    ntt::ntt_nwc(output.data(), p1, p2, degree, modulus);
    print_verify_output(result, output.data(), degree);
}

void test_ntt_nwc() {
    std::vector<uint64_t> p1 = {1, 2, 3, 4};
    std::vector<uint64_t> p2 = {5, 6, 7, 8};
    std::vector<uint64_t> result = {7625,7645,2,60};
    test_ntt_nwc(result.data(), p1.data(), p2.data(), 4, 7681);
}




int main() {
    std::cout << "Test HEXL NTT!" << std::endl;
    test_eltwise_mult_mod();
    test_ntt_nwc();

    return 0;
}