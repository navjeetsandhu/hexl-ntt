#include<iostream>
#include "ntt.hpp"
#include "custom_assert.h"

auto getData0() {
    return std::make_tuple(
            32, 769,
            std::vector<uint64_t>{401, 203, 221, 352, 487, 151, 405, 356,
                                  343, 424, 635, 757, 457, 280, 624, 353,
                                  496, 353, 624, 280, 457, 757, 635, 424,
                                  343, 356, 405, 151, 487, 352, 221, 203},
            std::vector<uint64_t>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                                  12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                                  23, 24, 25, 26, 27, 28, 29, 30, 31, 32});
}
void test_ntt_full(uint64_t *result, const uint64_t *operand, uint64_t N, uint64_t modulus) {
    int i;

    std::cout << "N: " << N << " Modulus: " << modulus << "\n";

    std::cout << "ComputeForward Input:\n";
    for(i=0;i<N;i++){
        std::cout << operand[i] << ' ';
    }
    std::cout << '\n';

    ntt::ntt_full(result, operand, N, modulus);

    std::cout << "ComputeInverse Output:\n";

    for(i=0;i<N;i++){
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';

    for(i=0;i<N;i++){
        c_assert(operand[i] == result[i]);
    }
    std::cout << "Test Pass" << '\n';

}
void test_ntt_full(std::tuple<uint64_t, uint64_t, std::vector<uint64_t>, std::vector<uint64_t>>&& input_data)

{
    uint64_t modulus = std::get<1>(input_data);
    uint64_t N = std::get<0>(input_data);
    std::vector<uint64_t> input = std::get<2>(input_data);
    std::vector<uint64_t> out_buffer_final(N);
    test_ntt_full(out_buffer_final.data(), input.data(), N, modulus);
}


int main() {
    std::cout << "Test Basic NTT!" << std::endl;
    test_ntt_full(getData0());
    return 0;
}
