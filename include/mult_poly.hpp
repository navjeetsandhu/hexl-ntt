#pragma once
#include <vector>

void mult_poly_naive(const std::vector<uint64_t> & p1, const std::vector<uint64_t> & p2,
                     std::vector<uint64_t>& res);
void mult_poly_naive_q(const std::vector<uint64_t>& p1, const std::vector<uint64_t>& p2,
                       uint64_t q, std::vector<uint64_t>& result);
void mult_poly_naive_q_cc(const std::vector<uint64_t>& p1, const std::vector<uint64_t>& p2,
                          uint64_t q, uint64_t d, std::vector<uint64_t>& result);
void mult_poly_naive_q_nwc(const std::vector<uint64_t>& p1, const std::vector<uint64_t>& p2,
                           uint64_t q, uint64_t d, std::vector<uint64_t>& result);