//  ----------------------------------------------------------------------------
//  Header file for the smt class.                              smt-compiler.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 27, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef GC_SMT_COMPILER_HPP
#define GC_SMT_COMPILER_HPP

#include "gc/ast/visitor.hpp"
#include <algorithm>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

namespace gc::compiler {

class SmtCompiler : public gc::ast::Visitor<string> {
  private:
    const gc::ast::Program* prog;
    std::string output; // the resulting smt formula
    int pnum = 0;       // tracks the number of missing trailing parentheses.

    // WP(havoc x, B) = B[a/x] (a fresh in B)
    std::map<string, string> havocs; // first is a unique location
    std::vector<string> locs;

  public:
    explicit SmtCompiler(const gc::ast::Program* prog) : prog(prog) {
        string body = visit(prog);
        stringstream ss;
        for (const auto& l : locs) {
            ss << "(declare-fun " << l << "() Int)\n";
        }
        ss << "\n";
        ss << "(assert (not " << body << "))";
        ss << "\n(check-sat)\n";
        ss << "(exit)\n";
        output = ss.str();
    }

    const string& compile() { return output; }

    // done
    string visit(const gc::ast::Program* program) override {
        stringstream ss;
        const auto& vc = program->commands;
        for (auto it = vc.begin(); it != vc.end(); ++it) {
            ss << visit(*it) << " ";
        }
        // append trailing parentheses.
        for (int i = 0; i < pnum; ++i) {
            ss << ")";
        }
        return ss.str();
    }

    string visit(const gc::ast::Command* command) override {
        stringstream ss;
        switch (command->type) {
        case gc::ast::Command::Type::Assume:
            ss << visit(dynamic_cast<const gc::ast::Assume*>(command));
            break;
        case gc::ast::Command::Type::Assert:
            ss << visit(dynamic_cast<const gc::ast::Assert*>(command));
            break;
        case gc::ast::Command::Type::Havoc:
            ss << visit(dynamic_cast<const gc::ast::Havoc*>(command));
            break;
        case gc::ast::Command::Type::Select:
            ss << visit(dynamic_cast<const gc::ast::Select*>(command));
            break;
        case gc::ast::Command::Type::List:
            ss << visit(dynamic_cast<const gc::ast::List*>(command));
            break;
        }
        return ss.str();
    }

    string visit(const gc::ast::Assume* a) override {
        stringstream ss;
        ss << "(=> " << visit(&a->assertion);
        pnum++;
        return ss.str();
    }

    string visit(const gc::ast::Assert* assert) override {
        stringstream ss;
        ss << "(and " << visit(&assert->assertion);
        pnum++;
        return ss.str();
    }

    string visit(const gc::ast::Havoc* h) override {
        stringstream ss;

        havocs[h->location.identifier] = h->fresh;

        if (std::find(locs.begin(), locs.end(), h->fresh) == locs.end()) {
            locs.push_back(h->fresh); // add to location list
        }

        return ss.str();
    }

    string visit(const gc::ast::List* list) override {
        stringstream ss;
        for (auto c : list->commands) {
            ss << visit(c) << "";
        }
        return ss.str();
    }

    string visit(const gc::ast::Select* choice) override {
        stringstream ss;
        ss << "(";
        for (auto command : choice->left) {
            ss << visit(command) << "\n ";
        }
        ss << "\b)\n";
        ss << " []\n";
        ss << "(";
        for (auto command : choice->right) {
            ss << visit(command) << "\n ";
        }
        ss << "\b)";
        return ss.str();
    }

    // TODO delegate this to lexical analysis
    string visit(const gc::ast::True* aTrue) override { return "true"; }

    // TODO delegate this to lexical analysis
    string visit(const gc::ast::False* aFalse) override { return "false"; }

    string visit(const gc::ast::Assertion* assertion) override {
        stringstream ss;
        switch (assertion->type) {
        case gc::ast::Assertion::Type::Negation:
            ss << visit(dynamic_cast<const gc::ast::Negation*>(assertion));
            break;
        case gc::ast::Assertion::Type::Disjunction:
            ss << visit(dynamic_cast<const gc::ast::Disjunction*>(assertion));
            break;
        case gc::ast::Assertion::Type::Conjunction:
            ss << visit(dynamic_cast<const gc::ast::Conjunction*>(assertion));
            break;
        case gc::ast::Assertion::Type::Implication:
            ss << visit(dynamic_cast<const gc::ast::Implication*>(assertion));
            break;
        case gc::ast::Assertion::Type::True:
            ss << visit(dynamic_cast<const gc::ast::True*>(assertion));
            break;
        case gc::ast::Assertion::Type::False:
            ss << visit(dynamic_cast<const gc::ast::False*>(assertion));
            break;
        case gc::ast::Assertion::Type::UniversalQuantification:
            ss << visit(
                dynamic_cast<const gc::ast::UniversalQuantifier*>(assertion));
            break;
        case gc::ast::Assertion::Type::ExistentialQuantification:
            ss << visit(
                dynamic_cast<const gc::ast::ExistentialQuantifier*>(assertion));
            break;
        case gc::ast::Assertion::Type::Comparison:
            ss << visit(dynamic_cast<const gc::ast::Comparison*>(assertion));
            break;
        }
        return ss.str();
    }

    string visit(const gc::ast::Location* location) override {
        stringstream ss;
        const string& str = location->identifier;
        if (!havocs[str].empty())
            ss << "" << havocs[str] << "";
        else
            ss << "" << str << "";
        if (std::find(locs.begin(), locs.end(), str) == locs.end()) {
            locs.push_back(str); // add to location list
        }
        return ss.str();
    }

    // done
    string visit(const gc::ast::Negation* assertion) override {
        stringstream ss;
        ss << "(not " << visit(&assertion->assertion) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Conjunction* a) override {
        stringstream ss;
        ss << "(and " << visit(&a->left) << " " << visit(&a->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Disjunction* a) override {
        stringstream ss;
        ss << "(or " << visit(&a->left) << " " << visit(&a->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Implication* a) override {
        stringstream ss;
        ss << "(=> " << visit(&a->left) << " " << visit(&a->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::UniversalQuantifier* assertion) override {
        stringstream ss;
        // (forall (x Type) (y Type) .. )
        ss << "(forall ";
        for (const auto& var : assertion->variables) {
            ss << "(" << var << " int)";
        }
        ss << " ";
        ss << visit(&assertion->body) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::ExistentialQuantifier* assertion) override {
        stringstream ss;
        ss << "(exists ";
        for (const auto& var : assertion->variables) {
            ss << "(" << var << " int)";
        }
        ss << " ";
        ss << visit(&assertion->body) << ")";
        return ss.str();
    }

    string visit(const gc::ast::Expression* expression) override {
        stringstream ss;
        switch (expression->type) {
        case gc::ast::Expression::Type::Location:
            ss << visit(dynamic_cast<const gc::ast::Location*>(expression));
            break;
        case gc::ast::Expression::Type::ArrayLocation:
            ss << visit(
                dynamic_cast<const gc::ast::ArrayLocation*>(expression));
            break;
        case gc::ast::Expression::Type::Constant:
            ss << visit(dynamic_cast<const gc::ast::Constant*>(expression));
            break;
        case gc::ast::Expression::Type::Negate:
            ss << visit(dynamic_cast<const gc::ast::Negate*>(expression));
            break;
        case gc::ast::Expression::Type::Sum:
            ss << visit(dynamic_cast<const gc::ast::Sum*>(expression));
            break;
        case gc::ast::Expression::Type::Subtract:
            ss << visit(dynamic_cast<const gc::ast::Subtract*>(expression));
            break;
        case gc::ast::Expression::Type::Multiply:
            ss << visit(dynamic_cast<const gc::ast::Multiply*>(expression));
            break;
        case gc::ast::Expression::Type::Divide:
            ss << visit(dynamic_cast<const gc::ast::Divide*>(expression));
            break;
        case gc::ast::Expression::Type::Mod:
            ss << visit(dynamic_cast<const gc::ast::Mod*>(expression));
            break;
        }
        return ss.str();
    }

    // done
    string visit(const gc::ast::Constant* expression) override {
        stringstream ss;
        ss << expression->number << "";
        return ss.str();
    }

    // done
    string visit(const gc::ast::ArrayLocation* e) override {
        stringstream ss;
        ss << "(select " << visit(&e->location) << " " << visit(&e->index)
           << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Negate* expression) override {
        stringstream ss;
        ss << "(- " << visit(&expression->expression) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Sum* e) override {
        stringstream ss;
        ss << "(+" << visit(&e->left) << " " << visit(&e->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Subtract* e) override {
        stringstream ss;
        ss << "(- " << visit(&e->left) << " " << visit(&e->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Multiply* e) override {
        stringstream ss;
        ss << "(* " << visit(&e->left) << " " << visit(&e->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Divide* e) override {
        stringstream ss;
        ss << "(div " << visit(&e->left) << " " << visit(&e->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::Mod* e) override {
        stringstream ss;
        ss << "(mod " << visit(&e->left) << " " << visit(&e->right) << ")";
        return ss.str();
    }

    string visit(const gc::ast::Comparison* comparison) override {
        stringstream ss;
        switch (comparison->type) {
        case gc::ast::Comparison::Type::EqualComparison:
            ss << visit(
                dynamic_cast<const gc::ast::EqualComparison*>(comparison));
            break;
        case gc::ast::Comparison::Type::NotEqualComparison:
            ss << visit(
                dynamic_cast<const gc::ast::NotEqualComparison*>(comparison));
            break;
        case gc::ast::Comparison::Type::LeqComparison:
            ss << visit(
                dynamic_cast<const gc::ast::LeqComparison*>(comparison));
            break;
        case gc::ast::Comparison::Type::GeqComparison:
            ss << visit(
                dynamic_cast<const gc::ast::GeqComparison*>(comparison));
            break;
        case gc::ast::Comparison::Type::LtComparison:
            ss << visit(dynamic_cast<const gc::ast::LtComparison*>(comparison));
            break;
        case gc::ast::Comparison::Type::GtComparison:
            ss << visit(dynamic_cast<const gc::ast::GtComparison*>(comparison));
            break;
        }
        return ss.str();
    }

    // done
    string visit(const gc::ast::EqualComparison* c) override {
        stringstream ss;
        ss << "(= " << visit(&c->left) << " " << visit(&c->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::NotEqualComparison* c) override {
        stringstream ss;
        ss << "(not (= " << visit(&c->left) << " " << visit(&c->right) << "))";
        return ss.str();
    }

    // done
    string visit(const gc::ast::LeqComparison* c) override {
        stringstream ss;
        ss << "(<= " << visit(&c->left) << " " << visit(&c->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::GeqComparison* c) override {
        stringstream ss;
        ss << "(>= " << visit(&c->left) << " " << visit(&c->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::LtComparison* c) override {
        stringstream ss;
        ss << "(< " << visit(&c->left) << " " << visit(&c->right) << ")";
        return ss.str();
    }

    // done
    string visit(const gc::ast::GtComparison* c) override {
        stringstream ss;
        ss << "(> " << visit(&c->left) << " " << visit(&c->right) << ")";
        return ss.str();
    }
};
} // namespace gc::compiler
#endif // GC_SMT_COMPILER_HPP
