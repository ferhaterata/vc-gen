//  ----------------------------------------------------------------------------
//  Header file for the PrinterVisitor class.                 PrinterVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef IMP_GC_COMPILER_HPP
#define IMP_GC_COMPILER_HPP

#include "visitor.hpp"
#include <sstream>

using namespace std;

namespace imp::compiler {

class GcCompiler : public imp::ast::Visitor<string> {
  private:
    const imp::ast::Program* prog;
    string output;

  public:
    const string& compile() const { return output; }

    explicit GcCompiler(const imp::ast::Program* prog) : prog(prog) {
        output = visit(prog);
    }

    string visit(const imp::ast::Node* node) override {}

    string visit(const imp::ast::BooleanExpression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case imp::ast::BooleanExpression::Type::NotExpression:
            ss << visit(
                dynamic_cast<const imp::ast::NotExpression*>(expression));
            break;
        case imp::ast::BooleanExpression::Type::OrExpression:
            ss << visit(
                dynamic_cast<const imp::ast::OrExpression*>(expression));
            break;
        case imp::ast::BooleanExpression::Type::AndExpression:
            ss << visit(
                dynamic_cast<const imp::ast::AndExpression*>(expression));
            break;
        case imp::ast::BooleanExpression::Type::Comparison:
            ss << visit(dynamic_cast<const imp::ast::Comparison*>(expression));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::NotExpression* expression) override {
        stringstream ss;
        ss << "(!" << visit(&expression->expression) << ")";
        return ss.str();
    }

    string visit(const imp::ast::OrExpression* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " || "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::AndExpression* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " && "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Assertion* assertion) override {
        stringstream ss;
        switch (assertion->type) {
        case imp::ast::Assertion::Type::Negation:
            ss << visit(dynamic_cast<const imp::ast::Negation*>(assertion));
            break;
        case imp::ast::Assertion::Type::Disjunction:
            ss << visit(dynamic_cast<const imp::ast::Disjunction*>(assertion));
            break;
        case imp::ast::Assertion::Type::Conjunction:
            ss << visit(dynamic_cast<const imp::ast::Conjunction*>(assertion));
            break;
        case imp::ast::Assertion::Type::Implication:
            ss << visit(dynamic_cast<const imp::ast::Implication*>(assertion));
            break;
        case imp::ast::Assertion::Type::UniversalQuantification:
            ss << visit(dynamic_cast<const imp::ast::UniversalQuantification*>(
                assertion));
            break;
        case imp::ast::Assertion::Type::ExistentialQuantification:
            ss << visit(
                dynamic_cast<const imp::ast::ExistentialQuantification*>(
                    assertion));
            break;
        case imp::ast::Assertion::Type::Comparison:
            ss << visit(dynamic_cast<const imp::ast::Comparison*>(assertion));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::Statement* statement) override {
        stringstream ss;
        switch (statement->type) {
        case imp::ast::Statement::Type::AssignmentStatement:
            ss << visit(dynamic_cast<const imp::ast::AssignmentStatement*>(statement));
            break;
        case imp::ast::Statement::Type::MultipleAssignmentStatement:
            ss << visit(
                dynamic_cast<const imp::ast::MultipleAssignmentStatement*>(statement));
            break;
        case imp::ast::Statement::Type::ArrayAssignmentStatement:
            ss << visit(
                dynamic_cast<const imp::ast::ArrayAssignmentStatement*>(statement));
            break;
        case imp::ast::Statement::Type::IfThenElseStatement:
            ss << visit(dynamic_cast<const imp::ast::IfThenElseStatement*>(statement));
            break;
        case imp::ast::Statement::Type::IfThenStatement:
            ss << visit(dynamic_cast<const imp::ast::IfThenStatement*>(statement));
            break;
        case imp::ast::Statement::Type::WhileStatement:
            ss << visit(dynamic_cast<const imp::ast::WhileStatement*>(statement));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::Location* location) override {
        stringstream ss;
        ss << "" << location->identifier << "";
        return ss.str();
    }

    string visit(const imp::ast::Invariant* invariant) override {
        stringstream ss;
        ss << "(invariant " << visit(&invariant->assertion) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Block* block) override {
        stringstream ss;
        ss << "(";
        for (const auto& node : block->stmts) {
            ss << visit(node) << "\n";
        }
        ss << "\b\b)";
        return ss.str();
    }

    string visit(const imp::ast::PreCondition* condition) override {
        stringstream ss;
        ss << "(precondition ";
        ss << visit(&condition->assertion) << ")";
        return ss.str();
    }

    string visit(const imp::ast::PostCondition* condition) override {
        stringstream ss;
        ss << "(postcondition ";
        ss << visit(&condition->assertion) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Program* program) override {
        stringstream ss;
        ss << "(program " << program->identifier << "\n  ";
        for (const auto& node : program->preConditions) {
            ss << visit(node);
        }
        ss << "\n  ";
        for (const auto& node : program->postConditions) {
            ss << visit(node);
        }
        ss << "\n";
        ss << " is\n  ";
        ss << visit(&program->block);
        return ss.str();
    }

    string visit(const imp::ast::Negation* assertion) override {
        stringstream ss;
        ss << "(not " << visit(&assertion->assertion) << " )";
        return ss.str();
    }

    string visit(const imp::ast::Conjunction* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->left) << " and "
           << visit(&assertion->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Disjunction* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->left) << " or "
           << visit(&assertion->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Implication* assertion) override {
        stringstream ss;
        ss << "(" << visit(&assertion->left) << " implies "
           << visit(&assertion->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::UniversalQuantification* assertion) override {
        stringstream ss;
        ss << "(forall ";
        for (const auto& var : assertion->variables) {
            ss << var << " ";
        }
        ss << "";
        ss << visit(&assertion->body) << ")";
        return ss.str();
    }

    string
    visit(const imp::ast::ExistentialQuantification* assertion) override {
        stringstream ss;
        ss << "(exists ";
        for (const auto& var : assertion->variables) {
            ss << var << " ";
        }
        ss << " ,";
        ss << visit(&assertion->body) << ")";
        return ss.str();
    }

    string visit(const imp::ast::ArithmeticExpression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case imp::ast::ArithmeticExpression::Type::Reference:
            ss << visit(dynamic_cast<const imp::ast::Reference*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::ArrayReference:
            ss << visit(dynamic_cast<const imp::ast::ArrayReference*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Constant:
            ss << visit(dynamic_cast<const imp::ast::Constant*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Negate:
            ss << visit(dynamic_cast<const imp::ast::Negate*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Sum:
            ss << visit(dynamic_cast<const imp::ast::Sum*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Subtract:
            ss << visit(dynamic_cast<const imp::ast::Subtract*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Multiply:
            ss << visit(dynamic_cast<const imp::ast::Multiply*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Divide:
            ss << visit(dynamic_cast<const imp::ast::Divide*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::Mod:
            ss << visit(dynamic_cast<const imp::ast::Mod*>(expression));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::Reference* expression) override {
        stringstream ss;
        ss << expression->identifier << "";
        return ss.str();
    }

    string visit(const imp::ast::Constant* expression) override {
        stringstream ss;
        ss << expression->number << "";
        return ss.str();
    }

    string visit(const imp::ast::ArrayReference* expression) override {
        stringstream ss;
        ss << visit(&expression->reference);
        ss << "[" << visit(&expression->index) << "]";
        return ss.str();
    }

    string visit(const imp::ast::Negate* expression) override {
        stringstream ss;
        ss << "(-" << visit(&expression->expression) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Sum* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " + "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Subtract* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " - "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Multiply* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " * "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Divide* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " / "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Mod* expression) override {
        stringstream ss;
        ss << "(" << visit(&expression->left) << " % "
           << visit(&expression->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::Comparison* comparison) override {
        stringstream ss;
        switch (comparison->type) {
        case imp::ast::Comparison::Type::EqualComparison:
            ss << visit(dynamic_cast<const imp::ast::EqualComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::NotEqualComparison:
            ss << visit(dynamic_cast<const imp::ast::NotEqualComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::LeqComparison:
            ss << visit(dynamic_cast<const imp::ast::LeqComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::GeqComparison:
            ss << visit(dynamic_cast<const imp::ast::GeqComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::LtComparison:
            ss << visit(dynamic_cast<const imp::ast::LtComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::GtComparison:
            ss << visit(dynamic_cast<const imp::ast::GtComparison*>(comparison));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::EqualComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left) << " = "
           << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::NotEqualComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left)
           << " != " << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::LeqComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left)
           << " <= " << visit(&comparison->right) << ")";
        return ss.str();
    }
    string visit(const imp::ast::GeqComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left)
           << " >= " << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::LtComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left) << " < "
           << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::GtComparison* comparison) override {
        stringstream ss;
        ss << "(" << visit(&comparison->left) << " > "
           << visit(&comparison->right) << ")";
        return ss.str();
    }

    string visit(const imp::ast::AssignmentStatement* statement) override {
        stringstream ss;
        ss << "(" << visit(&statement->loc) << ":=" << visit(&statement->expr)
           << ")";
        return ss.str();
    }

    string visit(const imp::ast::MultipleAssignmentStatement* statement) override {
        stringstream ss;
        ss << "(";
        ss << visit(&statement->locFirst) << ", ";
        ss << visit(&statement->locSecond) << ":=";
        ss << visit(&statement->exprFirst) << ", ";
        ss << visit(&statement->exprSecond) << ")";
        return ss.str();
    }

    string visit(const imp::ast::ArrayAssignmentStatement* statement) override {
        stringstream ss;
        ss << "(";
        ss << visit(&statement->loc);
        ss << "[" << visit(&statement->index) << "] := ";
        ss << visit(&statement->exp) << ")";
        return ss.str();
    }

    string visit(const imp::ast::IfThenStatement* statement) override {
        stringstream ss;
        ss << "(if " << visit(&statement->condition);
        ss << " then " << visit(&statement->thenBlock) << ")";
        return ss.str();
    }

    string visit(const imp::ast::IfThenElseStatement* statement) override {
        stringstream ss;
        ss << "(if " << visit(&statement->condition);
        ss << " then " << visit(&statement->thenBlock);
        ss << " else " << visit(&statement->elseBlock) << ")";
        return ss.str();
    }

    string visit(const imp::ast::WhileStatement* statement) override {
        stringstream ss;
        ss << "(while " << visit(&statement->condition) << "\n";
        for (const auto& invariant : statement->invariants) {
            ss << "  " << visit(invariant) << "\n";
        }
        ss << " do\n  ";
        ss << visit(&statement->block);
        ss << ")";
        return ss.str();
    }
};
} // namespace imp::compiler
#endif // IMP_GC_COMPILER_HPP
