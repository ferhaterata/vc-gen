//  ----------------------------------------------------------------------------
//  Header file for testing guarded commands.                           test.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 25, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "gc-driver.hpp"
#include "printer-visitor.hpp"
#include "tools.hpp"
#include <iostream>

void run(gc_driver&);

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
    gc::ast::PrinterVisitor visitor(driver.program);
    std::cout << visitor.getOutput() << std::endl;
    cout << "---------------------------------------------------------------\n";
    delete driver.program;
}
