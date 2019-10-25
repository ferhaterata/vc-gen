//  ----------------------------------------------------------------------------
//  Implementation file for the ast class.                               ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "ast.hpp"
using namespace ast;

inline ostream& operator<<(ostream& os, const ArithmeticExpression& exp) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const Assertion& assertion) {
    return os << typeid(Assertion).name();
}

inline ostream& operator<<(ostream& os, const BooleanExpression& assertion) {
    return os << typeid(BooleanExpression).name();
}

inline ostream& operator<<(ostream& os, const Statement& assertion) {
    return os << typeid(Statement).name();
}

inline ostream& operator<<(ostream& os, const Program& assertion) {
    return os << typeid(Program).name();
}

inline ostream& operator<<(ostream& os, const Invariant& assertion) {
    return os << typeid(Invariant).name();
}
