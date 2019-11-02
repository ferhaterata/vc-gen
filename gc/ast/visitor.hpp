//  ----------------------------------------------------------------------------
//  Header file for the visitor class.                        visitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef GC_VISITOR_HPP
#define GC_VISITOR_HPP

#include "gc.hpp"

namespace gc::ast {

class Node;
class Command;
class Expression;
class Location;
class Assertion;
class Assume;
class Assert;
class Havoc;
class List;
class Select;
class Program;
class Negation;
class True;
class False;
class Disjunction;
class Conjunction;
class Implication;
class UniversalQuantifier;
class ExistentialQuantifier;
class Comparison;
class Read;
class Write;
class Negate;
class Sum;
class Subtract;
class Multiply;
class Divide;
class Mod;
class Comparison;
class EqualComparison;
class NotEqualComparison;
class LeqComparison;
class GeqComparison;
class LtComparison;
class GtComparison;

template <class T> class Visitor {
  public:
    virtual T visit(const Command*) = 0;
    virtual T visit(const Expression*) = 0;
    virtual T visit(const Location*) = 0;
    virtual T visit(const Assertion*) = 0;
    virtual T visit(const Assume*) = 0;
    virtual T visit(const Assert*) = 0;
    virtual T visit(const Havoc*) = 0;
    virtual T visit(const List*) = 0;
    virtual T visit(const Select*) = 0;
    virtual T visit(const Program*) = 0;
    virtual T visit(const Negation*) = 0;
    virtual T visit(const True*) = 0;
    virtual T visit(const False*) = 0;
    virtual T visit(const Disjunction*) = 0;
    virtual T visit(const Conjunction*) = 0;
    virtual T visit(const Implication*) = 0;
    virtual T visit(const UniversalQuantifier*) = 0;
    virtual T visit(const ExistentialQuantifier*) = 0;
    virtual T visit(const Constant*) = 0;
    virtual T visit(const Read*) = 0;
    virtual T visit(const Write*) = 0;
    virtual T visit(const Negate*) = 0;
    virtual T visit(const Sum*) = 0;
    virtual T visit(const Subtract*) = 0;
    virtual T visit(const Multiply*) = 0;
    virtual T visit(const Divide*) = 0;
    virtual T visit(const Mod*) = 0;
    virtual T visit(const Comparison*) = 0;
    virtual T visit(const EqualComparison*) = 0;
    virtual T visit(const NotEqualComparison*) = 0;
    virtual T visit(const LeqComparison*) = 0;
    virtual T visit(const GeqComparison*) = 0;
    virtual T visit(const LtComparison*) = 0;
    virtual T visit(const GtComparison*) = 0;
};

} // namespace gc::ast

#endif // GC_VISITOR_HPP
