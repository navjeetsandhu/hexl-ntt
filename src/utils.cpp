#include"utils.hpp"

void print_results(const std::string& msg, const std::vector<uint64_t>& result){
    std::cout << msg << ": " << std::endl;
    for (uint64_t i : result)
        std::cout << i << ' ';
    std::cout << std::endl << std::endl;
}

void print_results(const std::string& msg, const uint64_t* result, const uint64_t n){
    std::cout << msg << ": " << std::endl;
    for (uint64_t i=0;i< n; i++)
        std::cout << result[i] << ' ';
    std::cout << std::endl << std::endl;
}

void print_signed_results(const std::string& msg, const std::vector<uint64_t>& result){
    std::cout << msg << ": " << std::endl;
    for (uint64_t i : result)
        std::cout <<  static_cast<typename std::make_signed<uint64_t>::type>(i) << ' ';

    std::cout << std::endl << std::endl;
}