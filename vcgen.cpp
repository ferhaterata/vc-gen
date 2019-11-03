//  ----------------------------------------------------------------------------
//  Header file for the imp class.                                     imp.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "gc/compiler/smt-compiler.hpp"
#include "gc/gc-driver.hpp"
#include "imp/ast/printer-visitor.hpp"
#include "imp/compiler/gc-compiler.hpp"
#include "imp/imp-driver.hpp"
#include "solver/z3-solver.hpp"
#include "tools.hpp"
#include <iostream>

void run(imp_driver&, gc_driver&);
std::string& erase(std::string&, const std::string&);
void printFile(const std::string&);

int main(int argc, char* argv[]) {
    banner();
    imp_driver impDriver;
    gc_driver gcDriver;
    for (int i = 1; i < argc; ++i)
        if (argv[i] == std::string("-p"))
            impDriver.trace_parsing = true;
        else if (argv[i] == std::string("-s"))
            impDriver.trace_scanning = true;
        else if (!impDriver.parse(argv[i])) {
            run(impDriver, gcDriver);
        } else
            return 1;
    bye();
    return 0;
}

void run(imp_driver& impDriver, gc_driver& gcDriver) {
    printFile(impDriver.file);
    cout << "\n";
    cout << "---------------------------------------------------------------\n";

    imp::ast::PrinterVisitor visitor(impDriver.program);
    std::cout << visitor.getOutput() << std::endl;
    cout << "---------------------------------------------------------------\n";

    imp::compiler::GcCompiler gcCompiler(impDriver.program);
    std::string gc = gcCompiler.compile();
    std::cout << gc << std::endl;
    std::string gcFileName = impDriver.program->identifier + ".gc";
    std::ofstream gc_fout(gcFileName);
    gc_fout << erase(gc, " \b");
    gc_fout.close();
    cout << "---------------------------------------------------------------\n";

    gcDriver.parse(gcFileName);
    gc::compiler::SmtCompiler smtCompiler(gcDriver.program);
    std::string smt = smtCompiler.compile();
    std::cout << smt << std::endl;
    const std::string& smtFileName = gcDriver.file + ".smt";
    std::ofstream smt_fout(smtFileName);
    smt_fout << erase(smt, ")\b ");
    smt_fout.close();
    cout << "---------------------------------------------------------------\n";

    Z3 solver;
    Result result = solver.run(smtFileName);
    switch (result) {
    case Result::SAT:
        cout << "sat :: Not Valid!";
        break;
    case Result::UNSAT:
        cout << "unsat :: Valid!";
        break;
    case Result::ERROR:
        cout << "Error in formula:\n";
        cout << solver.getResult();
        break;
    }
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
