//  ----------------------------------------------------------------------------
//  Header file for the AbstractVisitor class.            AbstractVisitor.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 24, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_ABSTRACT_VISITOR_HPP
#define VC_GEN_ABSTRACT_VISITOR_HPP
#include "ast.hpp"
#include <iostream>

namespace ast {

template <class T> class AbstractVisitor : public Visitor<T> {
  public:
    const Program* prog;

    explicit AbstractVisitor(const Program* program) : prog(program) {
        visit(program);
    }

    T visit(const Node* node) override {}

    T visit(const BooleanExpression* expression) override {
        switch (expression->type) {
        case BooleanExpression::Type::NotExpression:
            visit(dynamic_cast<const NotExpression*>(expression));
            break;
        case BooleanExpression::Type::OrExpression:
            visit(dynamic_cast<const OrExpression*>(expression));
            break;
        case BooleanExpression::Type::AndExpression:
            visit(dynamic_cast<const AndExpression*>(expression));
            break;
        case BooleanExpression::Type::Comparison:
            visit(dynamic_cast<const Comparison*>(expression));
            break;
        }
    }

    T visit(const NotExpression* expression) override {
        cout << *expression << endl;
        visit(&expression->expression);
    }

    T visit(const OrExpression* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
    }

    T visit(const AndExpression* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
        cout << "and expression" << endl;
    }

    T visit(const Assertion* assertion) override {
        switch (assertion->type) {
        case Assertion::Type::Negation:
            visit(dynamic_cast<const Negation*>(assertion));
            break;
        case Assertion::Type::Disjunction:
            visit(dynamic_cast<const Disjunction*>(assertion));
            break;
        case Assertion::Type::Conjunction:
            visit(dynamic_cast<const Conjunction*>(assertion));
            break;
        case Assertion::Type::Implication:
            visit(dynamic_cast<const Implication*>(assertion));
            break;
        case Assertion::Type::UniversalQuantification:
            visit(dynamic_cast<const UniversalQuantification*>(assertion));
            break;
        case Assertion::Type::ExistentialQuantification:
            visit(dynamic_cast<const ExistentialQuantification*>(assertion));
            break;
        case Assertion::Type::Comparison:
            visit(dynamic_cast<const Comparison*>(assertion));
            break;
        }
    }

    T visit(const Statement* statement) override {
        switch (statement->type) {
        case Statement::Type::AssignmentStatement:
            visit(dynamic_cast<const AssignmentStatement*>(statement));
            break;
        case Statement::Type::MultipleAssignmentStatement:
            visit(dynamic_cast<const MultipleAssignmentStatement*>(statement));
            break;
        case Statement::Type::ArrayAssignmentStatement:
            visit(dynamic_cast<const ArrayAssignmentStatement*>(statement));
            break;
        case Statement::Type::IfThenElseStatement:
            visit(dynamic_cast<const IfThenElseStatement*>(statement));
            break;
        case Statement::Type::IfThenStatement:
            visit(dynamic_cast<const IfThenStatement*>(statement));
            break;
        case Statement::Type::WhileStatement:
            visit(dynamic_cast<const WhileStatement*>(statement));
            break;
        }
    }

    T visit(const Location* location) override { cout << *location << endl; }

    T visit(const Invariant* invariant) override {
        cout << *invariant << endl;
        visit(&invariant->assertion);
    }

    T visit(const Block* block) override {
        cout << *block << endl;
        for (const auto& node : block->stmts) {
            visit(node);
        }
    }

    T visit(const PreCondition* condition) override {
        cout << *condition << endl;
        visit(&condition->assertion);
    }

    T visit(const PostCondition* condition) override {
        cout << *condition << endl;
        visit(&condition->assertion);
    }

    T visit(const Program* program) override {
        cout << *program << endl;
        for (const auto& node : program->preConditions) {
            visit(node);
        }
        for (const auto& node : program->postConditions) {
            visit(node);
        }
        visit(&program->block);
    }

    T visit(const Negation* assertion) override {
        cout << *assertion << endl;
        visit(&assertion->assertion);
    }

    T visit(const Conjunction* assertion) override {
        cout << *assertion << endl;
        visit(&assertion->left);
        visit(&assertion->right);
    }

    T visit(const Disjunction* assertion) override {
        cout << *assertion << endl;
        visit(&assertion->left);
        visit(&assertion->right);
    }

    T visit(const Implication* assertion) override {
        cout << *assertion << endl;
        visit(&assertion->left);
        visit(&assertion->right);
    }

    T visit(const UniversalQuantification* assertion) override {
        cout << *assertion << endl;
        visit(&assertion->body);
    }

    T visit(const ExistentialQuantification* assertion) override {
        cout << *assertion << endl;
        visit(&assertion->body);
    }

    T visit(const ArithmeticExpression* expression) override {
        switch (expression->type) {
        case ArithmeticExpression::Type::Reference:
            visit(dynamic_cast<const Reference*>(expression));
            break;
        case ArithmeticExpression::Type::ArrayReference:
            visit(dynamic_cast<const ArrayReference*>(expression));
            break;
        case ArithmeticExpression::Type::Constant:
            visit(dynamic_cast<const Constant*>(expression));
            break;
        case ArithmeticExpression::Type::Negate:
            visit(dynamic_cast<const Negate*>(expression));
            break;
        case ArithmeticExpression::Type::Sum:
            visit(dynamic_cast<const Sum*>(expression));
            break;
        case ArithmeticExpression::Type::Subtract:
            visit(dynamic_cast<const Subtract*>(expression));
            break;
        case ArithmeticExpression::Type::Multiply:
            visit(dynamic_cast<const Multiply*>(expression));
            break;
        case ArithmeticExpression::Type::Divide:
            visit(dynamic_cast<const Divide*>(expression));
            break;
        case ArithmeticExpression::Type::Mod:
            visit(dynamic_cast<const Mod*>(expression));
            break;
        }
    }

    T visit(const Reference* expression) override {
        cout << *expression << endl;
    }

    T visit(const Constant* expression) override {
        cout << *expression << endl;
    }

    T visit(const ArrayReference* expression) override {
        cout << *expression << endl;
        visit(&expression->reference);
        visit(&expression->index);
    }

    T visit(const Negate* expression) override {
        cout << *expression << endl;
        visit(&expression->expression);
    }

    T visit(const Sum* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
    }

    T visit(const Subtract* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
    }

    T visit(const Multiply* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
    }

    T visit(const Divide* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
    }

    T visit(const Mod* expression) override {
        cout << *expression << endl;
        visit(&expression->left);
        visit(&expression->right);
    }

    T visit(const Comparison* comparison) override {
        switch (comparison->type) {
        case Comparison::Type::EqualComparison:
            break;
        case Comparison::Type::NotEqualComparison:
            break;
        case Comparison::Type::LeqComparison:
            break;
        case Comparison::Type::GeqComparison:
            break;
        case Comparison::Type::LtComparison:
            break;
        case Comparison::Type::GtComparison:
            break;
        }
    }

    T visit(const EqualComparison* comparison) override {
        cout << *comparison << endl;
        visit(&comparison->left);
        visit(&comparison->right);
    }

    T visit(const NotEqualComparison* comparison) override {
        cout << *comparison << endl;
        visit(&comparison->left);
        visit(&comparison->right);
    }

    T visit(const LeqComparison* comparison) override {
        cout << *comparison << endl;
        visit(&comparison->left);
        visit(&comparison->right);
    }
    T visit(const GeqComparison* comparison) override {
        cout << *comparison << endl;
        visit(&comparison->left);
        visit(&comparison->right);
    }

    T visit(const LtComparison* comparison) override {
        cout << *comparison << endl;
        visit(&comparison->left);
        visit(&comparison->right);
    }

    T visit(const GtComparison* comparison) override {
        cout << *comparison << endl;
        visit(&comparison->left);
        visit(&comparison->right);
    }

    T visit(const AssignmentStatement* statement) override {
        cout << *statement << endl;
        visit(&statement->loc);
        visit(&statement->expr);
    }

    T visit(const MultipleAssignmentStatement* statement) override {
        cout << *statement << endl;
        visit(&statement->locFirst);
        visit(&statement->exprFirst);
        visit(&statement->locSecond);
        visit(&statement->exprSecond);
    }

    T visit(const ArrayAssignmentStatement* statement) override {
        cout << *statement << endl;
        visit(&statement->loc);
        visit(&statement->index);
        visit(&statement->exp);
    }

    T visit(const IfThenStatement* statement) override {
        cout << *statement << endl;
        visit(&statement->condition);
        visit(&statement->thenBlock);
    }

    T visit(const IfThenElseStatement* statement) override {
        cout << *statement << endl;
        visit(&statement->condition);
        visit(&statement->thenBlock);
        visit(&statement->elseBlock);
    }

    T visit(const WhileStatement* statement) override {
        cout << *statement << endl;
        visit(&statement->condition);
        for (const auto& invariant : statement->invariants) {
            visit(invariant);
        }
        visit(&statement->block);
    }
};

} // namespace ast
#endif // VC_GEN_ABSTRACT_VISITOR_HPP
