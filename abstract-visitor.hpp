//  ----------------------------------------------------------------------------
//  Header file for the AbstractVisitor class.            AbstractVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_ABSTRACT_VISITOR_HPP
#define VC_GEN_ABSTRACT_VISITOR_HPP
#include "ast.hpp"

namespace ast {

class AbstractVisitor : public Visitor {
  public:
    explicit AbstractVisitor(const Program* program) : prog(program) {
        visit(program);
    }

    const Program* prog;

    void visit(const BooleanExpression* expression) override {}
    void visit(const Comparison* comparison) override {}

    void visit(const NotExpression* expression) override {
        visit(&expression->expression);
    }

    void visit(const OrExpression* expression) override {
        visit(&expression->left);
        visit(&expression->right);
    }

    void visit(const AndExpression* expression) override {
        visit(&expression->left);
        visit(&expression->right);
    }

    void visit(const Assertion* assertion) override {}

    void visit(const Statement* statement) override {}

    void visit(const Location* location) override {}

    void visit(const Invariant* invariant) override {
        visit(&invariant->assertion);
    }

    void visit(const Block* block) override {
        for (const auto& node : block->stmts) {
            visit(node);
        }
    }

    void visit(const PreCondition* condition) override {
        visit(&condition->assertion);
    }

    void visit(const PostCondition* condition) override {
        visit(&condition->assertion);
    }

    void visit(const Program* program) override {
        for (const auto& node : program->preConditions) {
            visit(node);
        }
        for (const auto& node : program->postConditions) {
            visit(node);
        }
    }

    void visit(const Negation* assertion) override {
        visit(&assertion->assertion);
    }

    void visit(const Disjunction* assertion) override {
        visit(&assertion->left);
        visit(&assertion->right);
    }

    void visit(const Implication* assertion) override {
        visit(&assertion->left);
        visit(&assertion->right);
    }

    void visit(const UniversalQuantification* assertion) override {
        visit(&assertion->body);
    }

    void visit(const ExistentialQuantification* assertion) override {
        visit(&assertion->body);
    }

    void visit(const ArithmeticExpression* expression) override {}

    void visit(const Reference* expression) override {}

    void visit(const Constant* expression) override {}

    void visit(const ArrayReference* expression) override {
        visit(&expression->reference);
        visit(&expression->index);
    }

    void visit(const Negate* expression) override {
        visit(&expression->expression);
    }


};

} // namespace ast
#endif // VC_GEN_ABSTRACT_VISITOR_HPP
