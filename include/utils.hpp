#pragma once

#include<iostream>
#include <vector>
void print_results(const std::string& msg, const std::vector<uint64_t>& result);
void print_results(const std::string& msg, const uint64_t* result, uint64_t n);
void print_signed_results(const std::string& msg, const std::vector<uint64_t>& result);