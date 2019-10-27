//  ----------------------------------------------------------------------------
//  Header file for testing guarded commands.                           test.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 25, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "gc/gc-driver.hpp"
#include "gc/printer-visitor.hpp"
#include "gc/compiler/smt-compiler.hpp"
#include "tools.hpp"
#include <iostream>

void run(gc_driver&);
void printFile(const std::string&);

int main(int argc, char* argv[]) {
    banner();
    gc_driver driver;
    for (int i = 1; i < argc; ++i)
        if (argv[i] == std::string("-p"))
            driver.trace_parsing = true;
        else if (argv[i] == std::string("-s"))
            driver.trace_scanning = true;
        else if (!driver.parse(argv[i])) {
            run(driver);
        } else
            return 1;
    bye();
    return 0;
}

void run(gc_driver& driver) {
    printFile(driver.file);
    cout << "---------------------------------------------------------------\n";
    gc::ast::PrinterVisitor visitor(driver.program);
    std::cout << visitor.getOutput() << std::endl;
    cout << "---------------------------------------------------------------\n";
    gc::compiler::s compiler(driver.program);
    std::string gc = compiler.compile();
    std::cout << gc << std::endl;
    std::string filename = driver.program->identifier + ".smt";
    std::ofstream fout(filename);
}

// print the file
void printFile(const string& filename) {
    std::ifstream f(filename);
    if (f.is_open())
        std::cout << f.rdbuf();
}
