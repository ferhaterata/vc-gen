//  ----------------------------------------------------------------------------
//  Header file for the vcgen class.                                   vcgen.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "vcgen-driver.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    int res = 0;
    vcgen_driver driver;
    for (int i = 1; i < argc; ++i)
        if (argv[i] == std::string("-p"))
            driver.trace_parsing = true;
        else if (argv[i] == std::string("-s"))
            driver.trace_scanning = true;
        else if (!driver.parse(argv[i]))
            // std::cout << *driver.prog << std::endl;
            std::cout << std::endl;
        else
            res = 1;
    return res;
}
