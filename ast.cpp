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

ostream& operator<<(ostream& os, const Node& node) { return os; }

ostream& operator<<(ostream& os, const WhileStatement& statement) {
    os << " condition: " << statement.condition
       << " invariants: " << statement.invariants
       << " block: " << statement.block;
    return os;
}

ostream& operator<<(ostream& os, const BooleanExpression& expression) {
    os << expression;
    return os;
}
ostream& operator<<(ostream& os, const Invariant& invariant) {
    os << " assertion: " << invariant.assertion;
    return os;
}
ostream& operator<<(ostream& os, const Block& block) {
    os << " stmts: " << block.stmts;
    return os;
}
ostream& operator<<(ostream& os, const NotExpression& expression) {
    os << " expression: " << expression.expression;
    return os;
}
ostream& operator<<(ostream& os, const OrExpression& expression) {
    os << "(" << expression.left << " or " << expression.right << ")";
    return os;
}
ostream& operator<<(ostream& os, const AndExpression& expression) {
    os << "(" << expression.left << " and " << expression.right << ")";
    return os;
}
ostream& operator<<(ostream& os, const Assertion& assertion) { return os; }
ostream& operator<<(ostream& os, const Statement& statement) { return os; }
ostream& operator<<(ostream& os, const Location& location) {
    os << " identifier: " << location.identifier;
    return os;
}
ostream& operator<<(ostream& os, const PreCondition& condition) {
    os << " assertion: " << condition.assertion;
    return os;
}
ostream& operator<<(ostream& os, const PostCondition& condition) {
    os << " assertion: " << condition.assertion;
    return os;
}
ostream& operator<<(ostream& os, const Program& program) {
    os << " identifier: " << program.identifier
       << " preConditions: " << program.preConditions
       << " postConditions: " << program.postConditions
       << " block: " << program.block;
    return os;
}
ostream& operator<<(ostream& os, const Negation& negation) {
    os << " assertion: " << negation.assertion;
    return os;
}
ostream& operator<<(ostream& os, const Disjunction& disjunction) {
    os << " left: " << disjunction.left << " right: " << disjunction.right;
    return os;
}
ostream& operator<<(ostream& os, const Conjunction& conjunction) {
    os << " left: " << conjunction.left << " right: " << conjunction.right;
    return os;
}
ostream& operator<<(ostream& os, const Implication& implication) {
    os << " left: " << implication.left << " right: " << implication.right;
    return os;
}
ostream& operator<<(ostream& os, const UniversalQuantification& quant) {
    os << " variables: " << quant.variables << " body: " << quant.body;
    return os;
}
ostream& operator<<(ostream& os, const ExistentialQuantification& quant) {
    os << " variables: " << quant.variables << " body: " << quant.body;
    return os;
}
ostream& operator<<(ostream& os, const ArithmeticExpression& expression) {
    return os;
}
ostream& operator<<(ostream& os, const Reference& reference) {
    os << " identifier: " << reference.identifier;
    return os;
}
ostream& operator<<(ostream& os, const Constant& constant) {
    os << " number: " << constant.number;
    return os;
}
ostream& operator<<(ostream& os, const Negate& negate) {
    os << " expression: " << negate.expression;
    return os;
}
ostream& operator<<(ostream& os, const Sum& sum) {
    os << " left: " << sum.left << " right: " << sum.right;
    return os;
}
ostream& operator<<(ostream& os, const Subtract& subtract) {
    os << " left: " << subtract.left << " right: " << subtract.right;
    return os;
}
ostream& operator<<(ostream& os, const Multiply& multiply) {
    os << " left: " << multiply.left << " right: " << multiply.right;
    return os;
}
ostream& operator<<(ostream& os, const Divide& divide) {
    os << " left: " << divide.left << " right: " << divide.right;
    return os;
}
ostream& operator<<(ostream& os, const Comparison& comparison) { return os; }
ostream& operator<<(ostream& os, const Mod& mod) {
    os << " left: " << mod.left << " right: " << mod.right;
    return os;
}
ostream& operator<<(ostream& os, const EqualComparison& comparison) {
    os << " left: " << comparison.left << " right: " << comparison.right;
    return os;
}
ostream& operator<<(ostream& os, const NotEqualComparison& comparison) {
    os << " left: " << comparison.left << " right: " << comparison.right;
    return os;
}
ostream& operator<<(ostream& os, const LeqComparison& comparison) {
    os << " left: " << comparison.left << " right: " << comparison.right;
    return os;
}
ostream& operator<<(ostream& os, const GeqComparison& comparison) {
    os << " left: " << comparison.left << " right: " << comparison.right;
    return os;
}
ostream& operator<<(ostream& os, const LtComparison& comparison) {
    os << "(" << comparison.left << " < " << comparison.right << ")";
    return os;
}
ostream& operator<<(ostream& os, const GtComparison& comparison) {
    os << " left: " << comparison.left << " right: " << comparison.right;
    return os;
}
ostream& operator<<(ostream& os, const AssignmentStatement& statement) {
    os << " loc: " << statement.loc << " expr: " << statement.expr;
    return os;
}
ostream& operator<<(ostream& os, const MultipleAssignmentStatement& statement) {
    os << " locFirst: " << statement.locFirst
       << " locSecond: " << statement.locSecond
       << " exprFirst: " << statement.exprFirst
       << " exprSecond: " << statement.exprSecond;
    return os;
}
ostream& operator<<(ostream& os, const ArrayAssignmentStatement& statement) {
    os << " loc: " << statement.loc << " index: " << statement.index
       << " exp: " << statement.exp;
    return os;
}
ostream& operator<<(ostream& os, const IfThenStatement& statement) {
    os << " if (" << statement.condition << ") "
       << " then " << statement.thenBlock << " end ";
    return os;
}
ostream& operator<<(ostream& os, const IfThenElseStatement& statement) {
    os << " if (" << statement.condition << ") "
       << " then " << statement.thenBlock << " else: " << statement.elseBlock
       << " end ";
    return os;
}

ostream& operator<<(ostream& os, const ArrayReference& reference) {
    os << " reference: " << reference.reference
       << " index: " << reference.index;
    return os;
}
}