//  ----------------------------------------------------------------------------
//  Header file for the gc-driver class.                           gc-driver.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 25, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef GC_DRIVER_HPP
#define GC_DRIVER_HPP

#include "recognizer/gc-parser.hpp"
#include <map>
#include <string>
// Tell Flex the lexer's prototype ...
#define YY_DECL gc::gc_parser::symbol_type gclex(gc_driver& driver)

// ... and declare it for the parser's sake.
YY_DECL;
// Conducting the whole scanning and parsing of vcgen.

class gc_driver {
  public:
    gc::ast::Program* program = nullptr;  // the top level node of our final AST
    std::map<std::string, int> variables; // counters for each location name

    gc_driver();
    ~gc_driver() { delete program; };

    string fresh(const string& location);

    // Handling the scanner.
    void scan_begin();
    void scan_end();
    bool trace_scanning;
    // Run the parser on file F.
    // Return 0 on success.
    int parse(const std::string& f);
    // The name of the file being parsed.
    // Used later to pass the file name to the location tracker.
    std::string file;
    // Whether parser traces should be generated.
    bool trace_parsing;
    // Error handling.
    void error(const gc::location& l, const std::string& m);
    void error(const std::string& m);

    std::string getLine(unsigned lineno);
};

#endif // GC_DRIVER_HPP
