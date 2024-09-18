#include <iostream>
#include <vector>
#include "file.h"


int  read_uint32_data_from_file(std::string file_name, std::vector<uint32_t>& data) {
    std::cout << std::endl << "Reading from  " << file_name << std::endl;

    //std::ifstream file("../../test/torus32dist.txt");
    std::ifstream file("file_name");
    if (!file)
    {
        std::cerr << "Unable to open " << file_name << std::endl;
        return -1;
    }

    uint32_t value;
    while (file >> value)
    {
        // Push each value into the vector
        data.push_back(value);
    }

    file.close();
    return 0;
}
