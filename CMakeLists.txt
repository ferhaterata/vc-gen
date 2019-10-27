cmake_minimum_required(VERSION 3.15)
project(vc-gen)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        .
        imp imp/recognizer
        gc gc/recognizer
)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(
        imp-parser
        imp/imp-parser.yy
        ${CMAKE_CURRENT_SOURCE_DIR}/imp/recognizer/imp-parser.cpp
        COMPILE_FLAGS "--report=state --graph --warnings=all")
FLEX_TARGET(
        imp-scanner
        imp/imp-scanner.ll
        ${CMAKE_CURRENT_SOURCE_DIR}/imp/recognizer/imp-scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(imp-scanner imp-parser)

BISON_TARGET(
        gc-parser
        gc/gc-parser.yy
        ${CMAKE_CURRENT_SOURCE_DIR}/gc/recognizer/gc-parser.cpp
        COMPILE_FLAGS "--report=state --graph --warnings=all")
FLEX_TARGET(
        gc-scanner
        gc/gc-scanner.ll
        ${CMAKE_CURRENT_SOURCE_DIR}/gc/recognizer/gc-scanner.cpp)
ADD_FLEX_BISON_DEPENDENCY(gc-scanner gc-parser)

add_executable(vcgen
        vcgen.cpp
        ##########
        imp/imp-driver.cpp
        imp/imp-driver.hpp
        ${BISON_imp-parser_OUTPUTS}
        ${FLEX_imp-scanner_OUTPUTS}
        imp/imp.cpp
        imp/imp.hpp
        imp/visitor.hpp
        imp/abstract-visitor.hpp
        imp/printer-visitor.hpp
        ##########
        tools.cpp
        tools.hpp
        ##########
        gc/gc-driver.hpp
        gc/gc-driver.cpp
        ${BISON_gc-parser_OUTPUTS}
        ${FLEX_gc-scanner_OUTPUTS}
        gc/gc.hpp
        gc/gc.cpp
        gc/visitor.hpp
        gc/printer-visitor.hpp
        )

add_executable(gc
        gc/test.cpp
        ##########
        tools.cpp
        tools.hpp
        ##########
        gc/gc-driver.hpp
        gc/gc-driver.cpp
        ${BISON_gc-parser_OUTPUTS}
        ${FLEX_gc-scanner_OUTPUTS}
        gc/gc.hpp
        gc/gc.cpp
        gc/visitor.hpp
        gc/printer-visitor.hpp
        )