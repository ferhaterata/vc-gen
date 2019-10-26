cmake_minimum_required(VERSION 3.15)
project(vc-gen)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        .
        imp imp/recognizer
#        gc gc/recognizer
)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(
        vcgen-parser
        imp/vcgen-parser.yy
        ${CMAKE_CURRENT_SOURCE_DIR}/imp/recognizer/vcgen-parser.cpp
        COMPILE_FLAGS "--report=state --graph --warnings=all")
FLEX_TARGET(
        vcgen-scanner
        imp/vcgen-scanner.ll
        ${CMAKE_CURRENT_SOURCE_DIR}/imp/recognizer/vcgen-scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(vcgen-scanner vcgen-parser)

#BISON_TARGET(gc-parser gc/gc-parser.yy ${CMAKE_CURRENT_SOURCE_DIR}/gc/recognizer/gc-parser.cpp
#        COMPILE_FLAGS "--report=state --graph --warnings=all")
#FLEX_TARGET(gc-scanner gc/gc-scanner.ll ${CMAKE_CURRENT_SOURCE_DIR}/gc/recognizer/gc-scanner.cpp)
#ADD_FLEX_BISON_DEPENDENCY(gc-scanner gc-parser)

add_executable(vcgen
        vcgen.cpp
        ##########
        imp/vcgen-driver.cpp
        imp/vcgen-driver.hpp
        ${BISON_vcgen-parser_OUTPUTS}
        ${FLEX_vcgen-scanner_OUTPUTS}
        imp/imp.cpp
        imp/imp.hpp
        imp/visitor.hpp
        imp/abstract-visitor.hpp
        imp/printer-visitor.hpp
        ##########
        tools.cpp
        tools.hpp
        ##########
#        gc/gc.hpp
#        gc/gc.cpp
#        gc/gc-driver.hpp
#        gc/gc-driver.cpp
#        gc/test.cpp
#        ${BISON_gc-parser_OUTPUTS}
#        ${FLEX_gc-scanner_OUTPUTS}
        )
