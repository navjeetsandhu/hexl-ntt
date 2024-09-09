cmake_minimum_required(VERSION 3.28)
project(hexl_ntt)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(hexl_ntt
        include/aligned-allocator.hpp
        include/allocator.hpp
        include/check.hpp
        include/clang.hpp
        include/compiler.hpp
        include/defines.hpp
        include/fwd-ntt-avx512.hpp
        include/gcc.hpp
        include/inv-ntt-avx512.hpp
        include/msvc.hpp
        include/ntt-avx512-util.hpp
        include/ntt-default.hpp
        include/ntt-internal.hpp
        include/ntt.hpp
        include/number-theory.hpp
        include/types.hpp
        include/util.hpp
        include/avx512-util.hpp
        include/cpu-features.hpp
        include/logging.hpp
        include/util-internal.hpp
        src/fwd-ntt-avx512.cpp
        src/inv-ntt-avx512.cpp
        src/ntt-internal.cpp
        src/ntt-radix-2.cpp
        src/ntt-radix-4.cpp)


#------------------------------------------------------------------------------
# Third-party code...
#------------------------------------------------------------------------------
find_package(CpuFeatures CONFIG)
if (NOT CpuFeatures_FOUND)
    message(STATUS "CpuFeatures: pre-installed CpuFeatures not found")
    add_subdirectory(cmake/third-party/cpu-features)
else()
    message(STATUS "CpuFeatures: found")
    set_target_properties(CpuFeatures::cpu_features PROPERTIES IMPORTED_GLOBAL TRUE)
    add_library(cpu_features ALIAS CpuFeatures::cpu_features)
    get_target_property(
            CpuFeatures_INCLUDE_DIR
            CpuFeatures::cpu_features
            INTERFACE_INCLUDE_DIRECTORIES)
endif()
