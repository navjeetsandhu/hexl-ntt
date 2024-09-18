#include<iostream>
#include "ntt.hpp"

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
int main() {
    std::cout << "Test Basic NTT!" << std::endl;
    int i;
    auto data0 =   getData0();
    uint64_t modulus = std::get<1>(data0);
    uint64_t N = std::get<0>(data0);


    std::vector<uint64_t> input = std::get<2>(data0);

    std::vector<uint64_t> out_buffer_final(N);

    std::cout << "ComputeForward Input:\n";
    for(i=0;i<10;i++){
        std::cout << input[i] << ' ';
    }
    std::cout << '\n';

    ntt::ntt_full(out_buffer_final.data(), input.data(), N, modulus);

    std::cout << "ComputeInverse Output:\n";

    for(i=0;i<10;i++){
        std::cout << out_buffer_final[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}
