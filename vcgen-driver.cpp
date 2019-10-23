//  ----------------------------------------------------------------------------
//  Implementation file for the vcgen-driver class.             vcgen-driver.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "vcgen-driver.hpp"
#include "vcgen-parser.hpp"
#include <fstream>

vcgen_driver::vcgen_driver() : trace_scanning(false), trace_parsing(false) {
    variables["one"] = 1;
    variables["two"] = 2;
}

vcgen_driver::~vcgen_driver() {}

int vcgen_driver::parse(const std::string& f) {
    file = f;
    scan_begin();
    yy::vcgen_parser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();
    return res;
}

void vcgen_driver::error(const yy::location& l, const std::string& m) {
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

void vcgen_driver::error(const std::string& m) { std::cerr << m << std::endl; }

std::string vcgen_driver::getLine(unsigned lineno) {
    std::ifstream is(file);
    std::string line;
    if (is.is_open()) {
        for (int i = 1; std::getline(is, line); i++) {
            if (i == lineno)
                break;
        }
    } else
        std::cout << "Unable to open stream" << std::endl;
    return line;
}