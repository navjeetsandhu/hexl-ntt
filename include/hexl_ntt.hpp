#pragma once
#include "hexl/hexl.hpp"

namespace hexl_ntt {
    std::unique_ptr<intel::hexl::NTT> create_ntt(uint64_t N, uint64_t modulus);
    inline void compute_inverse(const uint64_t *result, const uint64_t *operand, std::unique_ptr<intel::hexl::NTT>& ntt);
    inline void compute_forward(uint64_t *result, const uint64_t *operand, std::unique_ptr<intel::hexl::NTT>& ntt);
    void eltwise_mult_mod(uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t n, uint64_t modulus);
    void test_hexl_ntt_nwc(uint64_t *result, const uint64_t *p1, const uint64_t *p2, uint64_t degree, uint64_t modulus);
    void test_hexl_ntt_full_loop(uint64_t *result, const uint64_t *operand, uint64_t N, uint64_t modulus);
}

