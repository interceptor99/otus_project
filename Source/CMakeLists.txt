cmake_minimum_required(VERSION 3.2)

project(ProjestWithGTest)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    #By default, new Visual Studio projects link the C runtimes dynamically
    #but GoogleTest links them statically. This will generate an error
    #Enabling this option will make gtest link the runtimes dynamically too
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)

add_executable(
    test_fixtures
    test/test_fixtures_list.cpp
    test/test_fixtures_vector.cpp
    test/test_main.cpp
)

target_include_directories(
    test_fixtures PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
    test_fixtures PRIVATE
    gtest
)

if (MSVC)
    target_compile_options(
        test_fixtures PRIVATE
        /W4
    )
else ()
    target_compile_options(
        test_fixtures PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
