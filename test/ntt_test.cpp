#include<iostream>
#include "ntt.hpp"
#include "custom_assert.h"
#include "file.h"

auto getData0() {
    return std::make_tuple(
            32, 769,
            std::vector<uint64_t>{401, 203, 221, 352, 487, 151, 405, 356,
                                  343, 424, 635, 757, 457, 280, 624, 353,
                                  496, 353, 624, 280, 457, 757, 635, 424,
                                  343, 356, 405, 151, 487, 352, 221, 203});
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
void test_ntt_full(std::tuple<uint64_t, uint64_t, std::vector<uint64_t>>&& input_data)

{
    uint64_t modulus = std::get<1>(input_data);
    uint64_t N = std::get<0>(input_data);
    std::vector<uint64_t> input = std::get<2>(input_data);
    std::vector<uint64_t> out_buffer_final(N);
    test_ntt_full(out_buffer_final.data(), input.data(), N, modulus);
}


void test_torus32_dist_ntt() {
    constexpr uint64_t modulus = 4611686018427365377ULL;
    constexpr uint64_t N = 1024;
    std::string file_name = "../../test/torus32dist.txt";
    std::vector<uint64_t> data;
    if(read_data_from_file(file_name, data)) {
        std::cout << "read_data_from_file failed" << '\n';
        return;
    }

    test_ntt_full(std::make_tuple(N, modulus, data));
}

int main() {
    std::cout << "Test Basic NTT!" << std::endl;
    test_ntt_full(getData0());
    test_torus32_dist_ntt();
    return 0;
}
