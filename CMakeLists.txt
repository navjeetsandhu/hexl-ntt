cmake_minimum_required(VERSION 3.28)
project(myTestHexl)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)
include_directories(test)

add_executable(myTestHexl
        include/aligned-allocator.hpp
        include/allocator.hpp
        include/check.hpp
        include/clang.hpp
        include/compiler.hpp
        include/defines.hpp
        include/gcc.hpp
        include/msvc.hpp
        include/ntt.hpp
        include/number-theory.hpp
        include/types.hpp
        include/util.hpp
        src/fwd-ntt-avx512.cpp
        src/fwd-ntt-avx512.hpp
        src/inv-ntt-avx512.cpp
        src/inv-ntt-avx512.hpp
        src/ntt-avx512-util.hpp
        src/ntt-default.hpp
        src/ntt-internal.cpp
        src/ntt-internal.hpp
        src/ntt-radix-2.cpp
        src/ntt-radix-4.cpp)
