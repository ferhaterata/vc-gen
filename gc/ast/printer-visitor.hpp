//  ----------------------------------------------------------------------------
//  Header file for the PrinterVisitor class.                 PrinterVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef GC_PRINTER_VISITOR_HPP
#define GC_PRINTER_VISITOR_HPP

#include "visitor.hpp"
#include <sstream>

using namespace std;

namespace gc::ast {

class PrinterVisitor : public Visitor<string> {
  private:
    const Program* prog;
    string output;
    int pnum = 0;

  public:
    const string& getOutput() const { return output; }

    explicit PrinterVisitor(const Program* prog) : prog(prog) {
        stringstream ss;
        ss << "" << visit(prog) << "";
        output = ss.str();
    }

    string visit(const Program* program) override {
        stringstream ss;
        auto& cv = prog->commands;
        for (auto c : cv) {
            ss << "" << visit(c) << " ";
        }
        ss << "\b";
        // append trailing parentheses.
        for (int i = 0; i < pnum; ++i) {
            ss << ")";
        }
        return ss.str();
    }

    string visit(const Command* command) override {
        stringstream ss;
        switch (command->type) {
        case Command::Type::Assume:
            ss << visit(dynamic_cast<const Assume*>(command));
            break;
        case Command::Type::Assert:
            ss << visit(dynamic_cast<const Assert*>(command));
            break;
        case Command::Type::Havoc:
            ss << visit(dynamic_cast<const Havoc*>(command));
            break;
        case Command::Type::Select:
            ss << visit(dynamic_cast<const Select*>(command));
            break;
        case Command::Type::List:
            ss << visit(dynamic_cast<const List*>(command));
            break;
        }
        return ss.str();
    }

    string visit(const Assume* assume) override {
        stringstream ss;
        ss << "(assume " << visit(&assume->assertion) << ";";
        pnum++;
        return ss.str();
    }

    string visit(const Assert* assert) override {
        stringstream ss;
        ss << "(assert " << visit(&assert->assertion) << ";";
        pnum++;
        return ss.str();
    }

    string visit(const Havoc* havoc) override {
        stringstream ss;
        ss << "(havoc " << visit(&havoc->location) << ";";
        pnum++;
        return ss.str();
    }

    string visit(const List* list) override {
        stringstream ss;
        for (auto command : list->commands) {
            ss << visit(command) << " ";
        }
        ss << "\b";
        return ss.str();
    }

    string visit(const Select* choice) override {
        int p = 0;
        stringstream ss;
        ss << "((";
        for (auto command : choice->left) {
            ss << visit(command) << " ";
            p++;
        }
        ss << "\b";
        // append trailing parentheses.
        for (int i = 0; i < p; ++i) {
            ss << ")";
        }
        ss << " [] ";
        pnum -= p;
        p = 0;
        for (auto command : choice->right) {
            ss << visit(command) << " ";
            p++;
        }
        ss << "\b";
        // append trailing parentheses.
        for (int i = 0; i < p; ++i) {
            ss << ")";
        }
        ss << ")";
        pnum -= p;
        pnum++;
        return ss.str();
    }

    string visit(const vector<gc::ast::Command*>& commands) {
        stringstream ss;
        ss << "";
        for (auto command : commands) {
            ss << visit(command) << " ";
        }
        ss << "\b";
        return ss.str();
    }

    string visit(const True* aTrue) override { return "true"; }

    string visit(const False* aFalse) override { return "false"; }

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
        case Assertion::Type::True:
            ss << visit(dynamic_cast<const True*>(assertion));
            break;
        case Assertion::Type::False:
            ss << visit(dynamic_cast<const False*>(assertion));
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
        }
        return ss.str();
    }

    string visit(const Location* location) override {
        stringstream ss;
        ss << "" << location->identifier << "";
        return ss.str();
    }

    string visit(const Negation* assertion) override {
        stringstream ss;
        ss << "not " << visit(&assertion->assertion) << " ";
        return ss.str();
    }

    string visit(const Conjunction* assertion) override {
        stringstream ss;
        ss << "" << visit(&assertion->left) << " and "
           << visit(&assertion->right) << "";
        return ss.str();
    }

    string visit(const Disjunction* assertion) override {
        stringstream ss;
        ss << "" << visit(&assertion->left) << " or "
           << visit(&assertion->right) << "";
        return ss.str();
    }

    string visit(const Implication* assertion) override {
        stringstream ss;
        ss << "" << visit(&assertion->left) << " implies "
           << visit(&assertion->right) << "";
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

    string visit(const Expression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case Expression::Type::Location:
            ss << visit(dynamic_cast<const Location*>(expression));
            break;
        case Expression::Type::ArrayLocation:
            ss << visit(dynamic_cast<const ArrayLocation*>(expression));
            break;
        case Expression::Type::Constant:
            ss << visit(dynamic_cast<const Constant*>(expression));
            break;
        case Expression::Type::Negate:
            ss << visit(dynamic_cast<const Negate*>(expression));
            break;
        case Expression::Type::Sum:
            ss << visit(dynamic_cast<const Sum*>(expression));
            break;
        case Expression::Type::Subtract:
            ss << visit(dynamic_cast<const Subtract*>(expression));
            break;
        case Expression::Type::Multiply:
            ss << visit(dynamic_cast<const Multiply*>(expression));
            break;
        case Expression::Type::Divide:
            ss << visit(dynamic_cast<const Divide*>(expression));
            break;
        case Expression::Type::Mod:
            ss << visit(dynamic_cast<const Mod*>(expression));
            break;
        }
        return ss.str();
    }

    string visit(const Constant* expression) override {
        stringstream ss;
        ss << expression->number << "";
        return ss.str();
    }

    string visit(const ArrayLocation* expression) override {
        stringstream ss;
        ss << visit(&expression->location);
        ss << "[" << visit(&expression->index) << "]";
        return ss.str();
    }

    string visit(const Negate* expression) override {
        stringstream ss;
        ss << "-" << visit(&expression->expression) << "";
        return ss.str();
    }

    string visit(const Sum* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " + "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const Subtract* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " - "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const Multiply* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " * "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const Divide* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " / "
           << visit(&expression->right) << "";
        return ss.str();
    }

    string visit(const Mod* expression) override {
        stringstream ss;
        ss << "" << visit(&expression->left) << " % "
           << visit(&expression->right) << "";
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
        ss << "" << visit(&comparison->left) << " = "
           << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const NotEqualComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left)
           << " != " << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const LeqComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left)
           << " <= " << visit(&comparison->right) << "";
        return ss.str();
    }
    string visit(const GeqComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left)
           << " >= " << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const LtComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left) << " < "
           << visit(&comparison->right) << "";
        return ss.str();
    }

    string visit(const GtComparison* comparison) override {
        stringstream ss;
        ss << "" << visit(&comparison->left) << " > "
           << visit(&comparison->right) << "";
        return ss.str();
    }
};
} // namespace gc::ast
#endif // GC_PRINTER_VISITOR_HPP
