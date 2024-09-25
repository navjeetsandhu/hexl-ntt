#include<iostream>
#include "ntt.hpp"

namespace ntt {
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

    void ntt_full(uint64_t *result, const uint64_t *operand, uint64_t N, uint64_t modulus) {
        auto ntt = ntt::create_ntt(N, modulus);

        std::vector<uint64_t> output(N);
        ntt::compute_forward(output.data(), operand, ntt);
        ntt::compute_inverse(result, output.data(), ntt);
    }

    void eltwise_mult_mod(uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus) {
        intel::hexl::EltwiseMultMod(result, p1, p2, degree, modulus,1);
    }


    void ntt_nwc(uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus) {
        auto ntt = ntt::create_ntt(degree, modulus);
        std::vector<uint64_t> output(degree);
        std::vector<uint64_t> p1_output(degree);
        std::vector<uint64_t> p2_output(degree);
        ntt::compute_forward(p1_output.data(), p1, ntt);
        ntt::compute_forward(p2_output.data(), p2, ntt);
        eltwise_mult_mod(output.data(), p1_output.data(), p2_output.data(), degree, modulus);
        ntt::compute_inverse(result, output.data(), ntt);
    }


}

