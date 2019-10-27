//  ----------------------------------------------------------------------------
//  Header file for the PrinterVisitor class.                 PrinterVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef IMP_GC_COMPILER_HPP
#define IMP_GC_COMPILER_HPP

#include "algorithm"
#include "visitor.hpp"
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace imp::compiler {

class GcCompiler : public imp::ast::Visitor<string> {
  private:
    const imp::ast::Program* prog;
    string output;
    std::vector<std::pair<string, string>> symbols;
    std::vector<std::string> havocs;

  public:
    const string& compile() const { return output; }

    explicit GcCompiler(const imp::ast::Program* prog) : prog(prog) {
        output = visit(prog);
    }

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
        ss << "!" << visit(&expression->expression) << "";
        return ss.str();
    }

    string visit(const imp::ast::OrExpression* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " || "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::AndExpression* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " && "
           << visit(&expression->right) << "";
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
            ss << visit(dynamic_cast<const imp::ast::UniversalQuantifier*>(
                assertion));
            break;
        case imp::ast::Assertion::Type::ExistentialQuantification:
            ss << visit(
                dynamic_cast<const imp::ast::ExistentialQuantifier*>(
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
            ss << visit(
                dynamic_cast<const imp::ast::AssignmentStatement*>(statement));
            break;
        case imp::ast::Statement::Type::MultipleAssignmentStatement:
            ss << visit(
                dynamic_cast<const imp::ast::MultipleAssignmentStatement*>(
                    statement));
            break;
        case imp::ast::Statement::Type::ArrayAssignmentStatement:
            ss << visit(dynamic_cast<const imp::ast::ArrayAssignmentStatement*>(
                statement));
            break;
        case imp::ast::Statement::Type::IfThenElseStatement:
            ss << visit(
                dynamic_cast<const imp::ast::IfThenElseStatement*>(statement));
            break;
        case imp::ast::Statement::Type::IfThenStatement:
            ss << visit(
                dynamic_cast<const imp::ast::IfThenStatement*>(statement));
            break;
        case imp::ast::Statement::Type::WhileStatement:
            ss << visit(
                dynamic_cast<const imp::ast::WhileStatement*>(statement));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::Location* location) override {
        // updating recent havoc list
        std::string str = location->identifier;
        std::vector<std::string>::iterator pos;
        pos = find(havocs.begin(), havocs.end(), str);
        if (pos == havocs.end())
            havocs.push_back(str);

        stringstream ss;
        ss << "" << location->identifier << "";
        return ss.str();
    }

    string visit(const imp::ast::Invariant* invariant) override {
        return visit(&invariant->assertion);
    }

    string visit(const imp::ast::Block* block) override {
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

    string visit(const imp::ast::PreCondition* condition) override {
        stringstream ss;
        ss << "assume " << visit(&condition->assertion) << ";";
        return ss.str();
    }

    string visit(const imp::ast::PostCondition* condition) override {
        stringstream ss;
        ss << "assert " << visit(&condition->assertion) << ";";
        return ss.str();
    }

    string visit(const imp::ast::Program* program) override {
        stringstream ss;
        if (!program->preConditions.empty()) {
            ss << "(";
            for (const auto& node : program->preConditions) {
                ss << visit(node) << " ";
            }
            ss << "\b)\n";
        }
        ss << visit(&program->block);
        ss << "\n";
        if (!program->postConditions.empty()) {
            ss << "(";
            for (const auto& node : program->postConditions) {
                ss << visit(node) << " ";
            }
            ss << "\b)";
        }
        return ss.str();
    }

    string visit(const imp::ast::Negation* assertion) override {
        stringstream ss;
        ss << "! " << visit(&assertion->assertion) << "";
        return ss.str();
    }

    string visit(const imp::ast::Conjunction* assertion) override {
        stringstream ss;
        ss << "" << visit(&assertion->left) << " && "
           << visit(&assertion->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Disjunction* assertion) override {
        stringstream ss;
        ss << "" << visit(&assertion->left) << " || "
           << visit(&assertion->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Implication* assertion) override {
        stringstream ss;
        ss << "" << visit(&assertion->left) << " ==> "
           << visit(&assertion->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::UniversalQuantifier* assertion) override {
        stringstream ss;
        ss << "forall ";
        for (const auto& var : assertion->variables) {
            ss << var << " ";
        }
        ss << "\b, ";
        ss << visit(&assertion->body) << "";
        return ss.str();
    }

    string
    visit(const imp::ast::ExistentialQuantifier* assertion) override {
        stringstream ss;
        ss << "exists ";
        for (const auto& var : assertion->variables) {
            ss << var << " ";
        }
        ss << "\b, ";
        ss << visit(&assertion->body) << "";
        return ss.str();
    }

    string visit(const imp::ast::ArithmeticExpression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case imp::ast::ArithmeticExpression::Type::Reference:
            ss << visit(dynamic_cast<const imp::ast::Reference*>(expression));
            break;
        case imp::ast::ArithmeticExpression::Type::ArrayReference:
            ss << visit(
                dynamic_cast<const imp::ast::ArrayReference*>(expression));
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

    // being used havocs here
    // TODO: check array fragment
    string visit(const imp::ast::Reference* expression) override {
        std::stringstream ss;

        string str = expression->identifier;
        for (const auto& pair : symbols) {
            if (pair.first == str) {
                ss << pair.second << "";
                return ss.str();
            }
        }
        ss << expression->identifier << "";
        return ss.str();
    }

    string visit(const imp::ast::Constant* expression) override {
        stringstream ss;
        ss << expression->number << "";
        return ss.str();
    }

    // TODO: check array fragment
    string visit(const imp::ast::ArrayReference* expression) override {
        stringstream ss;
        ss << visit(&expression->reference);
        ss << "[" << visit(&expression->index) << "]";
        return ss.str();
    }

    string visit(const imp::ast::Negate* expression) override {
        stringstream ss;
        ss << "-" << visit(&expression->expression) << "";
        return ss.str();
    }

    string visit(const imp::ast::Sum* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " + "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Subtract* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " - "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Multiply* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " * "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Divide* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " / "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Mod* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " % "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::Comparison* comparison) override {
        stringstream ss;
        switch (comparison->type) {
        case imp::ast::Comparison::Type::EqualComparison:
            ss << visit(
                dynamic_cast<const imp::ast::EqualComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::NotEqualComparison:
            ss << visit(
                dynamic_cast<const imp::ast::NotEqualComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::LeqComparison:
            ss << visit(
                dynamic_cast<const imp::ast::LeqComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::GeqComparison:
            ss << visit(
                dynamic_cast<const imp::ast::GeqComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::LtComparison:
            ss << visit(
                dynamic_cast<const imp::ast::LtComparison*>(comparison));
            break;
        case imp::ast::Comparison::Type::GtComparison:
            ss << visit(
                dynamic_cast<const imp::ast::GtComparison*>(comparison));
            break;
        }
        return ss.str();
    }

    string visit(const imp::ast::EqualComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left) << " = "
           << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::NotEqualComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left)
           << " != " << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::LeqComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left)
           << " <= " << visit(&comparison->right) << "";
        return ss.str();
    }
    string visit(const imp::ast::GeqComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left)
           << " >= " << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::LtComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left) << " < "
           << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::GtComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left) << " > "
           << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const imp::ast::AssignmentStatement* statement) override {
        stringstream ss;
        std::pair<string, string> pair(statement->loc.identifier,
                                       statement->loc.fresh);
        symbols.push_back(pair);
        ss << "(assume " << pair.second << " = " << pair.first << "; ";
        ss << "havoc " << pair.first << "; ";
        ss << "assume " << pair.first << " = " << visit(&statement->expr)
           << ";)";
        symbols.pop_back();
        // for other calls visit location
        visit(&statement->loc);
        return ss.str();
    }

    string
    visit(const imp::ast::MultipleAssignmentStatement* statement) override {
        stringstream ss;
        // First Assignment
        std::pair<string, string> pair(statement->locFirst.identifier,
                                       statement->locFirst.fresh);
        symbols.push_back(pair);
        ss << "(assume " << pair.second << " = " << pair.first << "; ";
        ss << "havoc " << pair.first << "; ";
        ss << "assume " << pair.first << " = " << visit(&statement->exprFirst)
           << ";)";
        symbols.pop_back();
        // for other calls visit location
        visit(&statement->exprFirst);
        ss << "\n";
        // Second Assignment
        pair.first = statement->locSecond.identifier;
        pair.second = statement->locSecond.fresh;
        symbols.push_back(pair);
        ss << "(assume " << pair.second << " = " << pair.first << "; ";
        ss << "havoc " << pair.first << "; ";
        ss << "assume " << pair.first << " = " << visit(&statement->exprSecond)
           << ";)";
        symbols.pop_back();
        // for other calls visit location
        visit(&statement->exprFirst);
        // Return both
        return ss.str();
    }

    // TODO: check array fragment
    string visit(const imp::ast::ArrayAssignmentStatement* statement) override {
        stringstream ss;
        std::pair<string, string> pair(statement->loc.identifier,
                                       statement->loc.fresh);
        symbols.push_back(pair);
        ss << "(assume " << pair.second << "[" << visit(&statement->index)
           << "]";
        ss << " = " << pair.first << "; ";
        ss << "havoc " << pair.first << "; ";
        ss << "assume " << pair.first << " = " << visit(&statement->exp)
           << ";)";
        symbols.pop_back();
        // for other calls visit location
        visit(&statement->loc);
        return ss.str();
    }

    string visit(const imp::ast::IfThenStatement* statement) override {
        stringstream ss;
        ss << "(";
        ss << "assume " << visit(&statement->condition) << ";";
        ss << visit(&statement->thenBlock);
        ss << ")";
        return ss.str();
    }

    string visit(const imp::ast::IfThenElseStatement* statement) override {
        stringstream ss;
        ss << "(";
        ss << "assume " << visit(&statement->condition) << ";";
        ss << visit(&statement->thenBlock);
        ss << "\n[]\n";
        ss << "assume !(" << visit(&statement->condition) << ");";
        ss << visit(&statement->elseBlock);
        ss << ")";
        return ss.str();
    }

    string visit(const imp::ast::WhileStatement* statement) override {
        stringstream ss;
        // assert I;
        ss << "(";
        for (const auto& invariant : statement->invariants) {
            ss << "assert " << visit(invariant) << "; ";
        }
        ss << "\b)\n";
        // havoc x1; ...; havoc xn;
        // collect modified locations for havoc
        visit(&statement->block);
        if (!havocs.empty()) {
            ss << "(";
            for (const auto& h : havocs) {
                ss << "havoc " << h << "; ";
            }
            ss << "\b)\n";
        }
        // assume I;
        ss << "(";

        for (const auto& invariant : statement->invariants) {
            ss << "assume " << visit(invariant) << "; ";
        }
        ss << "\b)\n";
        // (assume b; GC(c); assert I; assume false)
        // (assume b;
        ss << "(assume " << visit(&statement->condition) << ";\n";
        //  GC(c);
        ss << visit(&statement->block) << "\n";
        //  assert I;
        for (const auto& invariant : statement->invariants) {
            ss << "assert " << visit(invariant) << "; ";
        }
        // assume false;
        ss << "assume false;";
        ss << "\n[]\n";
        // assume ¬b )
        ss << "assume !(" << visit(&statement->condition) << ");)";
        havocs.clear();
        return ss.str();
    }
};
} // namespace imp::compiler
#endif // IMP_GC_COMPILER_HPP
