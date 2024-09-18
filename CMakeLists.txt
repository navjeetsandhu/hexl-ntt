cmake_minimum_required(VERSION 3.16)
project(hexl-ntt CXX)
set(CMAKE_CXX_STANDARD 17)
option(DEBUG "Debug mode" OFF)
if(DEBUG)
  set(CMAKE_CXX_FLAGS
      "-march=native -g -Wall -Wextra -pedantic -Wno-sign-compare")
else()
  set(CMAKE_CXX_FLAGS
      "-march=native -O3 -g -funroll-loops -Wall -Wextra -pedantic -Wno-sign-compare"
  )
  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()


option(USE_RANDEN "Use randen as CSPRNG" ON)
option(USE_HEXL "Use Intel HEXL" ON)
option(ENABLE_TEST "Build tests" ON)


set(hexl-ntt_DEFINITIONS
    ""
    PARENT_SCOPE)

if(USE_RANDEN)
  set(hexl-ntt_DEFINITIONS
      "${hexl-ntt_DEFINITIONS};USE_RANDEN"
      PARENT_SCOPE)
  add_compile_definitions(USE_RANDEN)
endif()


if(USE_HEXL)
  set(hexl-ntt_DEFINITIONS
      "${hexl-ntt_DEFINITIONS};USE_HEXL"
      PARENT_SCOPE)
  add_compile_definitions(USE_HEXL)
  add_subdirectory(thirdparties/hexl)
  # set(CMAKE_CXX_FLAGS "-march=native -O3 -g -funroll-loops -Wall -Wextra
  # -pedantic -Wno-sign-compare -mprefer-vector-width=512" )
endif()


if(USE_RANDEN)
  add_subdirectory(thirdparties/randen)
endif()

add_subdirectory(src)

if(ENABLE_TEST)
  add_subdirectory(test)
endif()

install(TARGETS hexl-ntt LIBRARY DESTINATION lib)
