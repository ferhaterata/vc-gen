cmake_minimum_required(VERSION 3.15)
project(vc-gen)

set(CMAKE_CXX_STANDARD 17)

include_directories(. recognizer)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(MyParser vcgen-parser.yy ${CMAKE_CURRENT_SOURCE_DIR}/recognizer/vcgen-parser.cpp)
FLEX_TARGET(MyScanner vcgen-scanner.ll ${CMAKE_CURRENT_SOURCE_DIR}/recognizer/vcgen-scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)


add_executable(vcgen
        vcgen-driver.cpp
        vcgen-driver.hpp
        vcgen.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
)
