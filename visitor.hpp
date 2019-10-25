//  ----------------------------------------------------------------------------
//  Header file for the visitor class.                        visitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_VISITOR_HPP
#define VC_GEN_VISITOR_HPP

#include "ast.hpp"

namespace ast {

class Statement;
class BooleanExpression;
class Program;
class Assertion;
class ArithmeticExpression;
class PreCondition;
class AndExpression;
class ArrayAssignmentStatement;
class ArrayReference;
class AssignmentStatement;
class Block;
class Comparison;
class Conjunction;
class Constant;
class Divide;
class Disjunction;
class EqualComparison;
class ExistentialQuantification;
class GeqComparison;
class GtComparison;
class IfThenElseStatement;
class IfThenStatement;
class Implication;
class Invariant;
class LeqComparison;
class Location;
class LtComparison;
class Mod;
class MultipleAssignmentStatement;
class Multiply;
class Negate;
class Negation;
class Node;
class NotEqualComparison;
class NotExpression;
class OrExpression;
class PostCondition;
class Reference;
class Subtract;
class Sum;
class WhileStatement;
class UniversalQuantification;

template <class T>
class Visitor {
  public:
    virtual T visit(const Statement*) = 0;
    virtual T visit(const BooleanExpression*) = 0;
    virtual T visit(const Assertion*) = 0;
    virtual T visit(const Program*) = 0;
    virtual T visit(const ArithmeticExpression*) = 0;
    virtual T visit(const PreCondition*) = 0;
    virtual T visit(const AndExpression*) = 0;
    virtual T visit(const ArrayAssignmentStatement*) = 0;
    virtual T visit(const ArrayReference*) = 0;
    virtual T visit(const AssignmentStatement*) = 0;
    virtual T visit(const Block*) = 0;
    virtual T visit(const Comparison*) = 0;
    virtual T visit(const Conjunction*) = 0;
    virtual T visit(const Constant*) = 0;
    virtual T visit(const Disjunction*) = 0;
    virtual T visit(const Divide*) = 0;
    virtual T visit(const EqualComparison*) = 0;
    virtual T visit(const ExistentialQuantification*) = 0;
    virtual T visit(const GeqComparison*) = 0;
    virtual T visit(const GtComparison*) = 0;
    virtual T visit(const IfThenElseStatement*) = 0;
    virtual T visit(const IfThenStatement*) = 0;
    virtual T visit(const Implication*) = 0;
    virtual T visit(const Invariant*) = 0;
    virtual T visit(const LeqComparison*) = 0;
    virtual T visit(const Location*) = 0;
    virtual T visit(const LtComparison*) = 0;
    virtual T visit(const Mod*) = 0;
    virtual T visit(const MultipleAssignmentStatement*) = 0;
    virtual T visit(const Multiply*) = 0;
    virtual T visit(const Negate*) = 0;
    virtual T visit(const Negation*) = 0;
    virtual T visit(const Node*) = 0;
    virtual T visit(const NotEqualComparison*) = 0;
    virtual T visit(const NotExpression*) = 0;
    virtual T visit(const OrExpression*) = 0;
    virtual T visit(const PostCondition*) = 0;
    virtual T visit(const Reference*) = 0;
    virtual T visit(const Subtract*) = 0;
    virtual T visit(const Sum*) = 0;
    virtual T visit(const UniversalQuantification*) = 0;
    virtual T visit(const WhileStatement*) = 0;
};

} // namespace ast

#endif // VC_GEN_VISITOR_HPP
