#pragma once
#include <vector>

void mult_poly_naive(const std::vector<uint64_t> & p1, const std::vector<uint64_t> & p2, std::vector<uint64_t>& res);
void mult_poly_naive_q(const std::vector<uint64_t>& a, const std::vector<uint64_t>& b, uint64_t q, std::vector<uint64_t>& result);