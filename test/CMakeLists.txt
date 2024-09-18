file(GLOB test_sources RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "*.cpp")

foreach(test_source ${test_sources})
    string( REPLACE ".cpp" "" test_name ${test_source} )
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} hexl-ntt)

endforeach(test_source ${test_sources})

if(APPLE)
    message("Compiling on macOS, Set following before building")
else()
    message("Not compiling on macOS")
endif()