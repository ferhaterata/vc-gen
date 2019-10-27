//  ----------------------------------------------------------------------------
//  Header file for the imp class.                                     imp.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "imp/compiler/gc-compiler.hpp"
#include "imp/imp-driver.hpp"
#include "ast/printer-visitor.hpp"
#include "gc/compiler/smt-compiler.hpp"
#include "tools.hpp"
#include <iostream>

void run(imp_driver&);
std::string& erase(std::string&, const std::string&);
void printFile(const std::string&);

int main(int argc, char* argv[]) {
    banner();
    imp_driver driver;
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

void run(imp_driver& driver) {
    printFile(driver.file);
    cout << "---------------------------------------------------------------\n";
    imp::ast::PrinterVisitor visitor(driver.program);
    std::cout << visitor.getOutput() << std::endl;
    cout << "---------------------------------------------------------------\n";
    imp::compiler::GcCompiler compiler(driver.program);
    std::string gc = compiler.compile();
    std::cout << gc << std::endl;
    std::string filename = driver.program->identifier + ".gc";
    std::ofstream fout(filename);
    fout << erase(gc, " \b");
    fout.close();
}

// print the file
void printFile(const string& filename) {
    std::ifstream f(filename);
    if (f.is_open())
        std::cout << f.rdbuf();
}

// Erase all Occurrences of given substring from main string.
std::string& erase(std::string& out, const std::string& to) {
    size_t pos;
    // Search for the substring in string in a loop untill nothing is found
    while ((pos = out.find(to)) != std::string::npos) {
        // If found then erase it from string
        out.erase(pos, to.length());
    }
    return out;
}
