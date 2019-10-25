//  ----------------------------------------------------------------------------
//  Implementation file for the ast class.                               ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "ast.hpp"
using namespace ast;

inline ostream& operator<<(ostream& os, const Statement& statement) {
    return os << typeid(Statement).name();
}

inline ostream& operator<<(ostream& os, const BooleanExpression& expression) {
    return os << typeid(BooleanExpression).name();
}

inline ostream& operator<<(ostream& os, const Assertion& assertion) {
    return os << typeid(Assertion).name();
}

inline ostream& operator<<(ostream& os, const Program& program) {
    return os << typeid(Program).name();
}

inline ostream& operator<<(ostream& os, const ArithmeticExpression& expr) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const PreCondition& condition) {
    return os << typeid(PreCondition).name();
}

inline ostream& operator<<(ostream& os, const AndExpression& expression) {
    return os << typeid(AndExpression).name();
}

inline ostream& operator<<(ostream& os, const ArrayAssignmentStatement& stmt) {
    return os << typeid(ArrayAssignmentStatement).name();
}

inline ostream& operator<<(ostream& os, const ArrayReference& exp) {
    return os << typeid(ArrayReference).name();
}

inline ostream& operator<<(ostream& os, const AssignmentStatement& statement) {


    return os << typeid(AssignmentStatement).name();
}

inline ostream& operator<<(ostream& os, const Block& block) {
    return os << typeid(Block).name();
}

inline ostream& operator<<(ostream& os, const Comparison& comparison) {
    return os << typeid(Comparison).name();
}

inline ostream& operator<<(ostream& os, const Conjunction& assertion) {
    return os << typeid(Conjunction).name();
}

inline ostream& operator<<(ostream& os, const Constant& expression) {
    return os << typeid(Constant).name();
}

inline ostream& operator<<(ostream& os, const Disjunction& assertion) {
    return os << typeid(Disjunction).name();
}

inline ostream& operator<<(ostream& os, const Divide& expression) {
    return os << typeid(Divide).name();
}

inline ostream& operator<<(ostream& os, const EqualComparison& exp) {
    return os << typeid(EqualComparison).name();
}

inline ostream& operator<<(ostream& os, const ExistentialQuantification& asst) {
    return os << typeid(ExistentialQuantification).name();
}

inline ostream& operator<<(ostream& os, const GeqComparison& comparison) {
    return os << typeid(GeqComparison).name();
}

inline ostream& operator<<(ostream& os, const GtComparison& comparison) {
    return os << typeid(GtComparison).name();
}

inline ostream& operator<<(ostream& os, const IfThenElseStatement& statement) {
    return os << typeid(IfThenElseStatement).name();
}

inline ostream& operator<<(ostream& os, const IfThenStatement& statement) {
    return os << typeid(IfThenStatement).name();
}

inline ostream& operator<<(ostream& os, const Implication& assertion) {
    return os << typeid(Implication).name();
}

inline ostream& operator<<(ostream& os, const Invariant& invariant) {
    return os << typeid(Invariant).name();
}

inline ostream& operator<<(ostream& os, const LeqComparison& comparison) {
    return os << typeid(LeqComparison).name();
}

inline ostream& operator<<(ostream& os, const Location& statement) {
    return os << typeid(Location).name();
}

inline ostream& operator<<(ostream& os, const LtComparison& comparison) {
    return os << typeid(LtComparison).name();
}

inline ostream& operator<<(ostream& os, const Mod& expression) {
    return os << typeid(expression).name();
}

inline ostream& operator<<(ostream& os,
                           const MultipleAssignmentStatement& statement) {
    return os << typeid(MultipleAssignmentStatement).name();
}

inline ostream& operator<<(ostream& os, const Multiply& expression) {
    return os << typeid(Multiply).name();
}

inline ostream& operator<<(ostream& os, const Negate& expression) {
    return os << typeid(Negate).name();
}

inline ostream& operator<<(ostream& os, const Negation& assertion) {
    return os << typeid(Negation).name();
}

inline ostream& operator<<(ostream& os, const Node& node) {
    return os << typeid(Node).name();
}

inline ostream& operator<<(ostream& os, const NotEqualComparison& comparison) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const NotExpression& expression) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const OrExpression& expression) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const PostCondition& postCondition) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const Reference& expression) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const Subtract& expression) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const Sum& expression) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const UniversalQuantification& assert) {
    return os << typeid(ArithmeticExpression).name();
}

inline ostream& operator<<(ostream& os, const WhileStatement& statement) {
    return os << typeid(ArithmeticExpression).name();
}