//  ----------------------------------------------------------------------------
//  Header file for the z3 class.                                  z3-solver.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 27, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef Z3_SOLVER_HPP
#define Z3_SOLVER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

enum class Result { SAT, UNSAT, ERROR };

class Z3 {
  private:
    const std::string cmd = "z3";
    std::string result;
    static std::string read(const std::string& file);
    static Result parse(const std::string& file);

  public:
    Z3() : result() {}
    Result run(const std::string& file) {
        std::string ss;
        std::string out = file + ".out";
        ss = cmd + " " + file + " > " + out;
        int i = std::system(ss.c_str());
        if (i != 0)
            std::cerr << "System call returned: " << i << std::endl;
        result = read(out);
        return parse(result);
    }

    std::string getResult() const { return result; }
};

inline std::string Z3::read(const std::string& file) {
    std::ifstream in(file.c_str(), std::ios::in | std::ios::binary);
    std::ostringstream contents;
    if (in) {
        contents << in.rdbuf();
        in.close();
    }
    return contents.str();
}

inline Result Z3::parse(const std::string& file) {
    std::size_t found = file.find("error");
    if (found != std::string::npos)
        return Result::ERROR;
    found = file.find("unsat");
    if (found != std::string::npos)
        return Result::UNSAT;
    return Result::SAT;
}

#endif // Z3_SOLVER_HPP
