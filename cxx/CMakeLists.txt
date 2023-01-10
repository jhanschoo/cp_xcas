cmake_minimum_required(VERSION 3.20)

project(cp_xcas CXX)

add_library(tutorial_compiler_flags INTERFACE)
find_package(Boost COMPONENTS chrono date_time REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})

target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)
target_compile_options(tutorial_compiler_flags INTERFACE "-Wall")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(cp_xcas_default_libs tutorial_compiler_flags CONAN_PKG::range-v3 ${Boost_LIBRARIES})

set(HARNESS_FILE "${CMAKE_BINARY_DIR}/harness.sh")
file(WRITE "${HARNESS_FILE}" "exec \"$1\" \"$2\" < \"$2\"\n")


include(CTest)

set(source_dirs 1.3.4.1_2 1.3.4.1_3 1.3.4.1_4)

foreach (source_dir IN LISTS source_dirs)
    add_executable(cp_xcas_${source_dir} "${source_dir}/main.cxx")
    target_link_libraries(cp_xcas_${source_dir} PUBLIC ${cp_xcas_default_libs})

    file(GLOB tests "${source_dir}/test*.txt")
    set(test_index 1)
    foreach (test IN LISTS tests)
        add_test(NAME "cp_xcas_${source_dir}_diagnostic_${test_index}"
                COMMAND sh
                "${HARNESS_FILE}"
                "$<TARGET_FILE:cp_xcas_${source_dir}>" "${test}"
                )
        math(EXPR test_index "${test_index} + 1")
    endforeach ()
endforeach ()
