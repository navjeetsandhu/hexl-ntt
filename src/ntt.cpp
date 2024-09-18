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

}

