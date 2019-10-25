//  ----------------------------------------------------------------------------
//  Header file for the PrinterVisitor class.                 PrinterVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_PRINTER_VISITOR_HPP
#define VC_GEN_PRINTER_VISITOR_HPP

#include "abstract-visitor.hpp"
#include <iostream>

using namespace std;

namespace ast {

class PrinterVisitor : public AbstractVisitor<void> {
  public:
    explicit PrinterVisitor(const Program* prog) : AbstractVisitor(prog) {}

    void visit(const NotExpression* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const OrExpression* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const AndExpression* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }

    void visit(const Statement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
    void visit(const Location* location) override {
        cout << location << endl;
        AbstractVisitor::visit(location);
    }
    void visit(const Invariant* invariant) override {
        cout << invariant << endl;
        AbstractVisitor::visit(invariant);
    }

    void visit(const Block* block) override {
        cout << block << endl;
        AbstractVisitor::visit(block);
    }

    void visit(const PreCondition* condition) override {
        cout << condition << endl;
        AbstractVisitor::visit(condition);
    }
    void visit(const PostCondition* condition) override {
        cout << condition << endl;
        AbstractVisitor::visit(condition);
    }
    void visit(const Program* program) override {
        cout << program << endl;
        AbstractVisitor::visit(program);
    }
    void visit(const Negation* assertion) override {
        cout << assertion << endl;
        AbstractVisitor::visit(assertion);
    }
    void visit(const Conjunction* assertion) override {
        cout << assertion << endl;
        AbstractVisitor::visit(assertion);
    }
    void visit(const Disjunction* assertion) override {
        cout << assertion << endl;
        AbstractVisitor::visit(assertion);
    }
    void visit(const Implication* assertion) override {
        cout << assertion << endl;
        AbstractVisitor::visit(assertion);
    }
    void visit(const UniversalQuantification* assertion) override {
        cout << assertion << endl;
        AbstractVisitor::visit(assertion);
    }
    void visit(const ExistentialQuantification* assertion) override {
        cout << assertion << endl;
        AbstractVisitor::visit(assertion);
    }
    void visit(const ArithmeticExpression* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Reference* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Constant* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const ArrayReference* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Negate* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Sum* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Subtract* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Multiply* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Divide* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Mod* expression) override {
        cout << expression << endl;
        AbstractVisitor::visit(expression);
    }
    void visit(const Comparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const EqualComparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const NotEqualComparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const LeqComparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const GeqComparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const LtComparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const GtComparison* comparison) override {
        cout << comparison << endl;
        AbstractVisitor::visit(comparison);
    }
    void visit(const AssignmentStatement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
    void visit(const MultipleAssignmentStatement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
    void visit(const ArrayAssignmentStatement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
    void visit(const IfThenStatement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
    void visit(const IfThenElseStatement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
    void visit(const WhileStatement* statement) override {
        cout << statement << endl;
        AbstractVisitor::visit(statement);
    }
};

} // namespace ast
#endif // VC_GEN_PRINTER_VISITOR_HPP
