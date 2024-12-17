cmake_minimum_required(VERSION 3.30)
project(jincc
        VERSION 0.1.0
        DESCRIPTION "A simple C compiler based on Boost.Spirit X3"
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/jin-iot/simple-c-compiler")

set(CMAKE_CXX_STANDARD 23)

find_package(Boost REQUIRED)

add_executable(jincc
               main.cpp
               compiler.cpp
               expression.cpp
               function.cpp
               statement.cpp
               vm.cpp)
target_link_libraries(jincc PRIVATE boost::boost)