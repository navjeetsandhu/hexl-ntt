#include"utils.hpp"

void print_results(const std::string& msg, const std::vector<uint64_t>& result){
    std::cout << msg << ": " << std::endl;
    for (uint64_t i : result)
        std::cout << i << ' ';
    std::cout << std::endl << std::endl;
}
