//  ----------------------------------------------------------------------------
//  Header file for the smt class.                              smt-compiler.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 27, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef GC_PURIFIER_HPP
#define GC_PURIFIER_HPP

#include "gc.hpp"
#include <sstream>
#include <vector>

using namespace std;

namespace gc::ast {

std::ostream& operator<<(std::ostream& out, const Command::Type& type) {
    switch (type) {
    case Command::Type::Assume:
        out << "Assume";
        break;
    case Command::Type::Assert:
        out << "Assert";
        break;
    case Command::Type::Havoc:
        out << "Havoc";
        break;
    case Command::Type::Select:
        out << "Select";
        break;
    case Command::Type::List:
        out << "List";
        break;
    }
}

class Purifier {
  private:
    gc::ast::Program* prog;
    std::vector<gc::ast::Command*> trace;

  public:
    explicit Purifier(gc::ast::Program* prog) : prog(prog) {
        auto& cv = prog->commands;
        for (auto rcit = cv.rbegin(); rcit != cv.rend(); ++rcit) {
            auto& c = (*rcit);
            visit(c);
        }
    }

    void visit(gc::ast::Command* command) {
        switch (command->type) {
        case gc::ast::Command::Type::Select: {
            auto s = dynamic_cast<gc::ast::Select*>(command);
            for (auto it = trace.begin(); it != trace.end(); ++it) {
                auto& t = (*it);
                Command* cpl = t->clone();
                Command* cpr = t->clone();
                t->removed = true;
                s->leftExt.push_back(cpl);
                s->rightExt.push_back(cpr);
            }
            trace.clear();
            auto choice = dynamic_cast<gc::ast::Select*>(command);
            for (auto c : choice->left) {
                visit(c);
            }
            for (auto c : choice->right) {
                visit(c);
            }
            break;
        }
        case gc::ast::Command::Type::List: {
            auto list = dynamic_cast<gc::ast::List*>(command);
            for (auto c : list->commands) {
                visit(c);
            }
            break;
        }
        default:
            trace.push_back(command);
            break;
        }
    }
};
} // namespace gc::ast
#endif // GC_PURIFIER_HPP
