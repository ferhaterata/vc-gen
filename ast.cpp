//  ----------------------------------------------------------------------------
//  Implementation file for the ast class.                               ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "ast.hpp"

namespace ast {

template <typename T> ostream& operator<<(ostream& out, const vector<T*>& v) {
    if (!v.empty()) {
        out << '[';
        for (const auto& node : v) {
            out << *node << ", ";
        }
        out << "\b\b]";
    }
    return out;
}

template <typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        for (const auto& node : v) {
            out << node << ", ";
        }
        out << "\b\b]";
    }
    return out;
}

template <typename T> ostream& print(ostream& out, const std::vector<T*>& v) {
    if (!v.empty()) {
        out << '[';
        for (const auto& node : v) {
            out << node << ", ";
        }
        out << "\b\b]";
    }
    return out;
}

}