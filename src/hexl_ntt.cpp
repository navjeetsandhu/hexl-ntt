#include<iostream>
#include "hexl_ntt.hpp"

namespace hexl_ntt {
    std::unique_ptr<intel::hexl::NTT> create_ntt(uint64_t N, uint64_t modulus) {
        auto ntt = std::make_unique<intel::hexl::NTT>(N, modulus);
        return ntt;
    }

    inline void compute_inverse(uint64_t *result, const uint64_t *operand, std::unique_ptr<intel::hexl::NTT>& ntt){
        ntt->ComputeInverse(result, operand, 1, 1);
    }


    inline void compute_forward(uint64_t *result, const uint64_t *operand, std::unique_ptr<intel::hexl::NTT>& ntt) {
        ntt->ComputeForward(result, operand, 1, 1);
    }

    void eltwise_mult_mod(uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus) {
        intel::hexl::EltwiseMultMod(result, p1, p2, degree, modulus,1);
    }

    void test_hexl_ntt_nwc(uint64_t *result, const uint64_t *p1, const uint64_t *p2,
                           uint64_t degree, uint64_t modulus) {
        auto ntt = hexl_ntt::create_ntt(degree, modulus);
        std::vector<uint64_t> output(degree);
        std::vector<uint64_t> p1_output(degree);
        std::vector<uint64_t> p2_output(degree);
        hexl_ntt::compute_forward(p1_output.data(), p1, ntt);
        hexl_ntt::compute_forward(p2_output.data(), p2, ntt);
        hexl_ntt::eltwise_mult_mod(output.data(), p1_output.data(),
                                   p2_output.data(), degree, modulus);
        hexl_ntt::compute_inverse(result, output.data(), ntt);
    }

    void test_hexl_ntt_full_loop(uint64_t *result, const uint64_t *operand, uint64_t N, uint64_t modulus) {
        auto ntt = hexl_ntt::create_ntt(N, modulus);
        std::vector<uint64_t> output(N);
        hexl_ntt::compute_forward(output.data(), operand, ntt);
        hexl_ntt::compute_inverse(result, output.data(), ntt);
    }
}

