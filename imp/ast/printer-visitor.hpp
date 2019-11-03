//  ----------------------------------------------------------------------------
//  Header file for the PrinterVisitor class.                 PrinterVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef IMP_PRINTER_VISITOR_HPP
#define IMP_PRINTER_VISITOR_HPP

#include "visitor.hpp"
#include <sstream>

using namespace std;

namespace imp::ast {

class PrinterVisitor : public Visitor<string> {
  private:
    const Program* prog;
    string output;

  public:
    const string& getOutput() const { return output; }

    explicit PrinterVisitor(const Program* prog) : prog(prog) {
        output = visit(prog);
    }

    string visit(const BooleanExpression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case BooleanExpression::Type::NotExpression:
            ss << visit(dynamic_cast<const NotExpression*>(expression));
            break;
        case BooleanExpression::Type::OrExpression:
            ss << visit(dynamic_cast<const OrExpression*>(expression));
            break;
        case BooleanExpression::Type::AndExpression:
            ss << visit(dynamic_cast<const AndExpression*>(expression));
            break;
        case BooleanExpression::Type::Comparison:
            ss << visit(dynamic_cast<const Comparison*>(expression));
            break;
        case BooleanExpression::Type::Parentheses:
            ss << visit(dynamic_cast<const BooleanParentheses*>(expression));
            break;
        }
        return ss.str();
    }

    string visit(const NotExpression* expression) override {
        stringstream ss;
        ss << "(!" << visit(&expression->expression) << ")";
        return ss.str();
    }

    string visit(const OrExpression* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " || "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const AndExpression* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " && "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const BooleanParentheses* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->inner) << ")";
        return ss.str();
    }

    string visit(const Assertion* assertion) override {
        stringstream ss;
        switch (assertion->type) {
        case Assertion::Type::Negation:
            ss << visit(dynamic_cast<const Negation*>(assertion));
            break;
        case Assertion::Type::Disjunction:
            ss << visit(dynamic_cast<const Disjunction*>(assertion));
            break;
        case Assertion::Type::Conjunction:
            ss << visit(dynamic_cast<const Conjunction*>(assertion));
            break;
        case Assertion::Type::Implication:
            ss << visit(dynamic_cast<const Implication*>(assertion));
            break;
        case Assertion::Type::UniversalQuantification:
            ss << visit(dynamic_cast<const UniversalQuantifier*>(assertion));
            break;
        case Assertion::Type::ExistentialQuantification:
            ss << visit(dynamic_cast<const ExistentialQuantifier*>(assertion));
            break;
        case Assertion::Type::Comparison:
            ss << visit(dynamic_cast<const Comparison*>(assertion));
            break;
        case Assertion::Type::Parentheses:
            ss << visit(dynamic_cast<const AssertionParentheses*>(assertion));
            break;
        }
        return ss.str();
    }

    string visit(const Statement* statement) override {
        stringstream ss;
        switch (statement->type) {
        case Statement::Type::AssignmentStatement:
            ss << visit(dynamic_cast<const AssignmentStatement*>(statement));
            break;
        case Statement::Type::MultipleAssignmentStatement:
            ss << visit(
                dynamic_cast<const MultipleAssignmentStatement*>(statement));
            break;
        case Statement::Type::ArrayAssignmentStatement:
            ss << visit(
                dynamic_cast<const ArrayAssignmentStatement*>(statement));
            break;
        case Statement::Type::IfThenElseStatement:
            ss << visit(dynamic_cast<const IfThenElseStatement*>(statement));
            break;
        case Statement::Type::IfThenStatement:
            ss << visit(dynamic_cast<const IfThenStatement*>(statement));
            break;
        case Statement::Type::WhileStatement:
            ss << visit(dynamic_cast<const WhileStatement*>(statement));
            break;
        }
        return ss.str();
    }

    string visit(const Location* location) override {
        stringstream ss;
        ss << "" << location->identifier << "";
        return ss.str();
    }

    string visit(const Invariant* invariant) override {
        stringstream ss;
        ss << "(invariant " << visit(&invariant->assertion) << ")";
        return ss.str();
    }

    string visit(const Block* block) override {
        stringstream ss;
        ss << "";
        int i = 1;
        int size = block->stmts.size();
        for (const auto& node : block->stmts) {
            ss << visit(node) << (i != size ? "\n" : "");
            i++;
        }
        return ss.str();
    }

    string visit(const PreCondition* condition) override {
        stringstream ss;
        ss << "(precondition ";
        ss << visit(&condition->assertion) << ")";
        return ss.str();
    }

    string visit(const PostCondition* condition) override {
        stringstream ss;
        ss << "(postcondition ";
        ss << visit(&condition->assertion) << ")";
        return ss.str();
    }

    string visit(const Program* program) override {
        stringstream ss;
        ss << "(program " << program->identifier << "\n  ";
        for (const auto& node : program->preConditions) {
            ss << visit(node) << "\n  ";
        }
        for (const auto& node : program->postConditions) {
            ss << visit(node) << "\n  ";
        }
        ss << "\b\b";
        ss << visit(&program->block);
        return ss.str();
    }

    string visit(const Negation* assertion) override {
        stringstream ss;
        ss << "(not " << visit(&assertion->assertion) << " )";
        return ss.str();
    }

    string visit(const Conjunction* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->left) << " and "
           << visit(&assertion->right) << ")";
        return ss.str();
    }

    string visit(const Disjunction* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->left) << " or "
           << visit(&assertion->right) << ")";
        return ss.str();
    }

    string visit(const Implication* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->left) << " implies "
           << visit(&assertion->right) << ")";
        return ss.str();
    }

    string visit(const AssertionParentheses* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->inner) << ")";
        return ss.str();
    }

    string visit(const UniversalQuantifier* assertion) override {
        stringstream ss;
        ss << "(forall ";
        for (const auto& var : assertion->variables) {
            ss << var << " ";
        }
        ss << "";
        ss << visit(&assertion->body) << ")";
        return ss.str();
    }

    string visit(const ExistentialQuantifier* assertion) override {
        stringstream ss;
        ss << "(exists ";
        for (const auto& var : assertion->variables) {
            ss << var << " ";
        }
        ss << " ,";
        ss << visit(&assertion->body) << ")";
        return ss.str();
    }

    string visit(const ArithmeticExpression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case ArithmeticExpression::Type::Reference:
            ss << visit(dynamic_cast<const Reference*>(expression));
            break;
        case ArithmeticExpression::Type::ArrayReference:
            ss << visit(dynamic_cast<const ArrayReference*>(expression));
            break;
        case ArithmeticExpression::Type::Constant:
            ss << visit(dynamic_cast<const Constant*>(expression));
            break;
        case ArithmeticExpression::Type::Negate:
            ss << visit(dynamic_cast<const Negate*>(expression));
            break;
        case ArithmeticExpression::Type::Sum:
            ss << visit(dynamic_cast<const Sum*>(expression));
            break;
        case ArithmeticExpression::Type::Subtract:
            ss << visit(dynamic_cast<const Subtract*>(expression));
            break;
        case ArithmeticExpression::Type::Multiply:
            ss << visit(dynamic_cast<const Multiply*>(expression));
            break;
        case ArithmeticExpression::Type::Divide:
            ss << visit(dynamic_cast<const Divide*>(expression));
            break;
        case ArithmeticExpression::Type::Mod:
            ss << visit(dynamic_cast<const Mod*>(expression));
            break;
        case ArithmeticExpression::Type::Parentheses:
            ss << visit(dynamic_cast<const ArithmeticParentheses*>(expression));
            break;
        }
        return ss.str();
    }

    string visit(const Reference* expression) override {
        stringstream ss;
        ss << expression->identifier << "";
        return ss.str();
    }

    string visit(const Constant* expression) override {
        stringstream ss;
        ss << expression->number << "";
        return ss.str();
    }

    string visit(const ArrayReference* expression) override {
        stringstream ss;
        ss << visit(&expression->reference);
        ss << "[" << visit(&expression->index) << "]";
        return ss.str();
    }

    string visit(const Negate* expression) override {
        stringstream ss;
        ss << "(-" << visit(&expression->expression) << ")";
        return ss.str();
    }

    string visit(const Sum* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " + "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const Subtract* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " - "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const Multiply* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " * "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const Divide* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " / "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const Mod* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " % "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const ArithmeticParentheses* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->inner) << ")";
        return ss.str();
    }

    string visit(const Comparison* comparison) override {
        stringstream ss;
        switch (comparison->type) {
        case Comparison::Type::EqualComparison:
            ss << visit(dynamic_cast<const EqualComparison*>(comparison));
            break;
        case Comparison::Type::NotEqualComparison:
            ss << visit(dynamic_cast<const NotEqualComparison*>(comparison));
            break;
        case Comparison::Type::LeqComparison:
            ss << visit(dynamic_cast<const LeqComparison*>(comparison));
            break;
        case Comparison::Type::GeqComparison:
            ss << visit(dynamic_cast<const GeqComparison*>(comparison));
            break;
        case Comparison::Type::LtComparison:
            ss << visit(dynamic_cast<const LtComparison*>(comparison));
            break;
        case Comparison::Type::GtComparison:
            ss << visit(dynamic_cast<const GtComparison*>(comparison));
            break;
        }
        return ss.str();
    }

    string visit(const EqualComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left) << " = "
           << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const NotEqualComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left)
           << " != " << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const LeqComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left)
           << " <= " << visit(&comparison->right) << ")";
        return ss.str();
    }
    string visit(const GeqComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left)
           << " >= " << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const LtComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left) << " < "
           << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const GtComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left) << " > "
           << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const AssignmentStatement* statement) override {
        stringstream ss;
        ss << "(" << visit(&statement->loc) << " := " << visit(&statement->expr)
           << ")";
        return ss.str();
    }

    string visit(const MultipleAssignmentStatement* statement) override {
        stringstream ss;
        ss << "(";
        ss << visit(&statement->locFirst) << ", ";
        ss << visit(&statement->locSecond) << " := ";
        ss << visit(&statement->exprFirst) << ", ";
        ss << visit(&statement->exprSecond) << ")";
        return ss.str();
    }

    string visit(const ArrayAssignmentStatement* statement) override {
        stringstream ss;
        ss << "(";
        ss << visit(&statement->loc);
        ss << "[" << visit(&statement->index) << "] := ";
        ss << visit(&statement->exp) << ")";
        return ss.str();
    }

    string visit(const IfThenStatement* statement) override {
        stringstream ss;
        ss << "(if " << visit(&statement->condition);
        ss << " then " << visit(&statement->thenBlock) << ")";
        return ss.str();
    }

    string visit(const IfThenElseStatement* statement) override {
        stringstream ss;
        ss << "(if " << visit(&statement->condition);
        ss << " then " << visit(&statement->thenBlock);
        ss << " else " << visit(&statement->elseBlock) << ")";
        return ss.str();
    }

    string visit(const WhileStatement* statement) override {
        stringstream ss;
        ss << "(while " << visit(&statement->condition) << "\n";
        for (const auto& invariant : statement->invariants) {
            ss << "  " << visit(invariant) << "\n";
        }
        ss << "";
        ss << visit(&statement->block);
        ss << ")";
        return ss.str();
    }
};
} // namespace imp::ast
#endif // IMP_PRINTER_VISITOR_HPP
