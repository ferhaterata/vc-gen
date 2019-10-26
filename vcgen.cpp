//  ----------------------------------------------------------------------------
//  Header file for the vcgen class.                                   vcgen.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "printer-visitor.hpp"
#include "tools.hpp"
#include "vcgen-driver.hpp"
#include <iostream>

void run(vcgen_driver&);

int main(int argc, char* argv[]) {
    banner();
    vcgen_driver driver;
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

void run(vcgen_driver& driver) {
    imp::ast::PrinterVisitor visitor(driver.program);
    std::cout << visitor.getOutput() << std::endl;
    cout << "---------------------------------------------------------------\n";
    delete driver.program;
}
