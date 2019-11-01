//  ----------------------------------------------------------------------------
//  Header file for the gc_driver class.                           gc-driver.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 25, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "gc-driver.hpp"
#include "ast/gc.hpp"
#include "recognizer/gc-parser.hpp"
#include <fstream>
#include <sstream>

gc_driver::gc_driver() : trace_scanning(false), trace_parsing(false) {}

int gc_driver::parse(const std::string& f) {
    file = f;
    scan_begin();
    gc::gc_parser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();
    return res;
}

void gc_driver::error(const gc::location& l, const std::string& m) {
    std::cerr << l << ": " << m << std::endl;
    // For undefined tokens, bison currently just tells us something
    // like 'unexpected $undefined' without printing the offending
    // character. This is much more useful:
    unsigned col = l.begin.column;
    unsigned len = l.end.column - col;
    unsigned bLine = l.begin.line;
    // TODO: The reported location is not entirely satisfying.
    std::cerr << "    " << getLine(bLine) << "\n";
    std::cerr << "    " << std::string(col - 1, ' ');
    std::cerr << std::string(len, '^') << std::endl;
}

void gc_driver::error(const std::string& m) { std::cerr << m << std::endl; }

std::string gc_driver::getLine(unsigned lineno) {
    std::ifstream is(file);
    std::string line;
    if (is.is_open()) {
        for (unsigned i = 1; std::getline(is, line); i++) {
            if (i == lineno)
                break;
        }
    } else
        std::cout << "Unable to open stream" << std::endl;
    return line;
}