file(GLOB hexl-ntt_sources "*.cpp")

if(ENABLE_SHARED)
  add_library(hexl-ntt SHARED ${hexl-ntt_sources})
else()
  add_library(hexl-ntt STATIC ${hexl-ntt_sources})
endif()

target_include_directories(
  hexl-ntt
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/thirdparties/hexl/hexl/hexl/include
    ${PROJECT_SOURCE_DIR}/thirdparties/randen
    ${PROJECT_SOURCE_DIR}/thirdparties/spqlios)

if(USE_RANDEN)
  target_link_libraries(hexl-ntt INTERFACE randen)
endif()

target_link_libraries(hexl-ntt INTERFACE HEXL::hexl)

