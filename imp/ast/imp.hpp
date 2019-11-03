//  ----------------------------------------------------------------------------
//  Declaration and Definition of AST classes.                           ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_IMP_HPP
#define VC_GEN_IMP_HPP

#include "../../tools.hpp"
#include "visitor.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace imp::ast {

// -----------------------------------------------------------------------------
class Node {
  public:
    Node() = default;
    virtual ~Node() = default;
};

// -----------------------------------------------------------------------------
class BooleanExpression : public Node {
  public:
    enum class Type {
        NotExpression,
        OrExpression,
        AndExpression,
        Comparison,
        Parentheses,
    };
    const Type type;
    explicit BooleanExpression(const Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class NotExpression : public BooleanExpression {
  public:
    const BooleanExpression& expression;

    explicit NotExpression(BooleanExpression& expression)
        : BooleanExpression(Type::NotExpression), expression(expression) {}

    ~NotExpression() override { d(imp::ast::NotExpression) delete &expression; }
};

// -----------------------------------------------------------------------------
class OrExpression : public BooleanExpression {
  public:
    const BooleanExpression& left;
    const BooleanExpression& right;

    OrExpression(BooleanExpression& left, BooleanExpression& right)
        : BooleanExpression(Type::OrExpression), left(left), right(right) {}

    ~OrExpression() override {
        d(imp::ast::OrExpression) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class AndExpression : public BooleanExpression {
  public:
    const BooleanExpression& left;
    const BooleanExpression& right;

    AndExpression(BooleanExpression& left, BooleanExpression& right)
        : BooleanExpression(Type::AndExpression), left(left), right(right) {}

    ~AndExpression() override {
        d(imp::ast::AndExpression) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class BooleanParentheses : public BooleanExpression {
  public:
    const BooleanExpression& inner;

    BooleanParentheses(BooleanExpression& inner)
        : BooleanExpression(BooleanExpression::Type::Parentheses),
          inner(inner) {}

    ~BooleanParentheses() override {
        d(imp::ast::BooleanParentheses) delete &inner;
    }
};

// -----------------------------------------------------------------------------
class Assertion : public Node {
  public:
    enum class Type {
        Negation,
        Disjunction,
        Conjunction,
        Implication,
        UniversalQuantification,
        ExistentialQuantification,
        Comparison,
        Parentheses,
    };
    const Type type;
    explicit Assertion(Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class Statement : public Node {
  public:
    enum class Type {
        AssignmentStatement,
        MultipleAssignmentStatement,
        ArrayAssignmentStatement,
        IfThenElseStatement,
        IfThenStatement,
        WhileStatement
    };
    Type type;
    explicit Statement(Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class Location : public Node {
  public:
    const string identifier;
    const string fresh;

    explicit Location(string identifier, string fresh)
        : identifier(std::move(identifier)), fresh(std::move(fresh)) {}

    ~Location() override { d(imp::ast::Location) }
};

// -----------------------------------------------------------------------------
class Invariant : public Node {
  public:
    const Assertion& assertion;

    explicit Invariant(Assertion& assertion) : assertion(assertion) {}

    ~Invariant() override { d(imp::ast::Invariant) delete &assertion; }
};

// -----------------------------------------------------------------------------
class Block : public Node {
  public:
    vector<Statement*> stmts;

    explicit Block(vector<Statement*> stmts) : stmts(std::move(stmts)) {}

    ~Block() override { d(imp::ast::Block) for (auto s : stmts) delete s; }
};

// -----------------------------------------------------------------------------
class PreCondition : public Node {
  public:
    const Assertion& assertion;

    explicit PreCondition(Assertion& assertion) : assertion(assertion) {}

    ~PreCondition() override { d(imp::ast::PreCondition) delete &assertion; }
};

// -----------------------------------------------------------------------------
class PostCondition : public Node {
  public:
    const Assertion& assertion;

    explicit PostCondition(Assertion& assertion) : assertion(assertion) {}

    ~PostCondition() override { d(imp::ast::PostCondition) delete &assertion; }
};

// -----------------------------------------------------------------------------
class Program : public Node {
  public:
    const string identifier;
    const vector<PreCondition*> preConditions;
    const vector<PostCondition*> postConditions;
    const Block& block;

    Program(string& identifier, vector<PreCondition*> preConditions,
            vector<PostCondition*> postConditions, Block& block)
        : identifier(identifier), preConditions(std::move(preConditions)),
          postConditions(std::move(postConditions)), block(block) {}

    ~Program() override {
        d(imp::ast::Program) delete &block;
        for (auto p : preConditions)
            delete p;
        for (auto p : postConditions)
            delete p;
    }
};

// -----------------------------------------------------------------------------
class Negation : public Assertion {
  public:
    const Assertion& assertion;

    explicit Negation(Assertion& assertion)
        : Assertion(Type::Negation), assertion(assertion) {}

    ~Negation() override { d(imp::ast::Negation) delete &assertion; }
};

// -----------------------------------------------------------------------------
class Disjunction : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Disjunction(Assertion& left, Assertion& right)
        : Assertion(Type::Disjunction), left(left), right(right) {}

    ~Disjunction() override {
        d(imp::ast::Disjunction) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Conjunction : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Conjunction(Assertion& left, Assertion& right)
        : Assertion(Type::Conjunction), left(left), right(right) {}

    ~Conjunction() override {
        d(imp::ast::Conjunction) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Implication : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Implication(Assertion& left, Assertion& right)
        : Assertion(Type::Implication), left(left), right(right) {}

    ~Implication() override {
        d(imp::ast::Implication) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class AssertionParentheses : public Assertion {
  public:
    const Assertion& inner;

    AssertionParentheses(Assertion& inner)
        : Assertion(Assertion::Type::Parentheses), inner(inner) {}

    ~AssertionParentheses() override {
        d(imp::ast::AssertionParentheses) delete &inner;
    }
};

// -----------------------------------------------------------------------------
class UniversalQuantifier : public Assertion {
  public:
    const vector<string> variables;
    const Assertion& body;

    UniversalQuantifier(vector<string> variables, Assertion& body)
        : Assertion(Type::UniversalQuantification),
          variables(std::move(variables)), body(body) {}

    ~UniversalQuantifier() override {
        d(imp::ast::UniversalQuantifier) delete &body;
    }
};

// -----------------------------------------------------------------------------
class ExistentialQuantifier : public Assertion {
  public:
    const vector<string> variables;
    const Assertion& body;

    ExistentialQuantifier(vector<string> variables, Assertion& body)
        : Assertion(Type::ExistentialQuantification),
          variables(std::move(variables)), body(body) {}

    ~ExistentialQuantifier() override {
        d(imp::ast::ExistentialQuantifier) delete &body;
    }
};

// -----------------------------------------------------------------------------
class ArithmeticExpression : public Node {

  public:
    enum class Type {
        Reference,
        ArrayReference,
        Constant,
        Negate,
        Sum,
        Subtract,
        Multiply,
        Divide,
        Mod,
        Parentheses
    };
    Type type;
    explicit ArithmeticExpression(Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class Reference : public ArithmeticExpression {
  public:
    const string identifier;

    explicit Reference(string identifier)
        : ArithmeticExpression::ArithmeticExpression(Type::Reference),
          identifier(std::move(identifier)) {}

    ~Reference() override { d(imp::ast::Reference) }
};

// -----------------------------------------------------------------------------
class Constant : public ArithmeticExpression {
  public:
    const int number;

    explicit Constant(const int number)
        : ArithmeticExpression(Type::Constant), number(number) {}

    ~Constant() override { d(imp::ast::Constant) }
};

// -----------------------------------------------------------------------------
class ArrayReference : public ArithmeticExpression {
  public:
    const Reference& reference;
    const ArithmeticExpression& index;

    ArrayReference(Reference& reference, ArithmeticExpression& index)
        : ArithmeticExpression(Type::ArrayReference), reference(reference),
          index(index) {}

    ~ArrayReference() override {
        d(imp::ast::ArrayReference) delete &index;
        delete &reference;
    }
};

// -----------------------------------------------------------------------------
class Negate : public ArithmeticExpression {
  public:
    const ArithmeticExpression& expression;

    explicit Negate(ArithmeticExpression& expression)
        : ArithmeticExpression(Type::Negate), expression(expression) {}

    ~Negate() override { d(imp::ast::Negate) delete &expression; }
};

// -----------------------------------------------------------------------------
class Sum : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Sum(ArithmeticExpression& left, ArithmeticExpression& right)
        : ArithmeticExpression(Type::Sum), left(left), right(right) {}

    ~Sum() override {
        d(imp::ast::Sum) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Subtract : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Subtract(ArithmeticExpression& left, ArithmeticExpression& right)
        : ArithmeticExpression(Type::Subtract), left(left), right(right) {}

    ~Subtract() override {
        d(imp::ast::Subtract) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Multiply : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Multiply(ArithmeticExpression& left, ArithmeticExpression& right)
        : ArithmeticExpression(Type::Multiply), left(left), right(right) {}

    ~Multiply() override {
        d(imp::ast::Multiply) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Divide : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Divide(ArithmeticExpression& left, ArithmeticExpression& right)
        : ArithmeticExpression(Type::Divide), left(left), right(right) {}

    ~Divide() override {
        d(imp::ast::Divide) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Mod : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Mod(ArithmeticExpression& left, ArithmeticExpression& right)
        : ArithmeticExpression(Type::Mod), left(left), right(right) {}

    ~Mod() override {
        d(imp::ast::Mod) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class ArithmeticParentheses : public ArithmeticExpression {
  public:
    const ArithmeticExpression& inner;

    ArithmeticParentheses(ArithmeticExpression& inner)
        : ArithmeticExpression(ArithmeticExpression::Type::Parentheses),
          inner(inner) {}

    ~ArithmeticParentheses() override {
        d(imp::ast::ArithmeticParentheses) delete &inner;
    }
};

// -----------------------------------------------------------------------------
class Comparison : public BooleanExpression, public Assertion {
  public:
    enum class Type {
        EqualComparison,
        NotEqualComparison,
        LeqComparison,
        GeqComparison,
        LtComparison,
        GtComparison,
    };
    Type type;

    explicit Comparison(Comparison::Type type)
        : BooleanExpression(BooleanExpression::Type::Comparison),
          Assertion(Assertion::Type::Comparison), type(type) {}
};

// -----------------------------------------------------------------------------
class EqualComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    EqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : Comparison(Comparison::Type::EqualComparison), left(left),
          right(right) {}

    ~EqualComparison() override {
        d(imp::ast::EqualComparison) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class NotEqualComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    NotEqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : Comparison(Comparison::Type::NotEqualComparison), left(left),
          right(right) {}

    ~NotEqualComparison() override {
        d(imp::ast::NotEqualComparison) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class LeqComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    LeqComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : Comparison(Comparison::Type::LeqComparison), left(left),
          right(right) {}

    ~LeqComparison() override {
        d(imp::ast::LeqComparison) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class GeqComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    GeqComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : Comparison(Comparison::Type::GeqComparison), left(left),
          right(right) {}

    ~GeqComparison() override {
        d(imp::ast::GeqComparison) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class LtComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    LtComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : Comparison(Comparison::Type::LtComparison), left(left), right(right) {
    }

    ~LtComparison() override {
        d(imp::ast::LtComparison) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class GtComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    GtComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : Comparison(Comparison::Type::GtComparison), left(left), right(right) {
    }

    ~GtComparison() override {
        d(imp::ast::GtComparison) delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class AssignmentStatement : public Statement {
  public:
    const Location& loc;
    const ArithmeticExpression& expr;

    AssignmentStatement(Location& loc, ArithmeticExpression& expr)
        : Statement(Statement::Type::AssignmentStatement), loc(loc),
          expr(expr) {}

    ~AssignmentStatement() override {
        d(imp::ast::AssignmentStatement) delete &loc;
        delete &expr;
    }
};

// -----------------------------------------------------------------------------
class MultipleAssignmentStatement : public Statement {
  public:
    const Location& locFirst;
    const Location& locSecond;
    const ArithmeticExpression& exprFirst;
    const ArithmeticExpression& exprSecond;

    MultipleAssignmentStatement(Location& locFirst, Location& locSecond,
                                ArithmeticExpression& exprFirst,
                                ArithmeticExpression& exprSecond)
        : Statement(Statement::Type::MultipleAssignmentStatement),
          locFirst(locFirst), locSecond(locSecond), exprFirst(exprFirst),
          exprSecond(exprSecond) {}

    ~MultipleAssignmentStatement() override {
        d(imp::ast::MultipleAssignmentStatement) delete &locFirst;
        delete &locSecond;
        delete &exprFirst;
        delete &exprSecond;
    }
};

// -----------------------------------------------------------------------------
class ArrayAssignmentStatement : public Statement {
  public:
    const Location& loc;
    const ArithmeticExpression& index;
    const ArithmeticExpression& exp;

    ArrayAssignmentStatement(Location& loc, ArithmeticExpression& index,
                             ArithmeticExpression& exp)
        : Statement(Statement::Type::ArrayAssignmentStatement), loc(loc),
          index(index), exp(exp) {}

    ~ArrayAssignmentStatement() override {
        d(imp::ast::ArrayAssignmentStatement) delete &loc;
        delete &index;
        delete &exp;
    }
};

// -----------------------------------------------------------------------------
class IfThenStatement : public Statement {
  public:
    const BooleanExpression& condition;
    const Block& thenBlock;

    IfThenStatement(BooleanExpression& condition, Block& thenBlock)
        : Statement(Statement::Type::IfThenStatement), condition(condition),
          thenBlock(thenBlock) {}

    ~IfThenStatement() override {
        d(imp::ast::IfThenStatement) delete &condition;
        delete &thenBlock;
    }
};

// -----------------------------------------------------------------------------
class IfThenElseStatement : public Statement {
  public:
    const BooleanExpression& condition;
    const Block& thenBlock;
    const Block& elseBlock;

    IfThenElseStatement(BooleanExpression& condition, Block& thenBlock,
                        Block& elseBlock)
        : Statement(Statement::Type::IfThenElseStatement), condition(condition),
          thenBlock(thenBlock), elseBlock(elseBlock) {}

    ~IfThenElseStatement() override {
        d(imp::ast::IfThenElseStatement) delete &condition;
        delete &thenBlock;
        delete &elseBlock;
    }
};

// -----------------------------------------------------------------------------
class WhileStatement : public Statement {
  public:
    const BooleanExpression& condition;
    const vector<Invariant*> invariants;
    const Block& block;

    WhileStatement(BooleanExpression& condition, vector<Invariant*> invariants,
                   Block& block)
        : Statement(Statement::Type::WhileStatement), condition(condition),
          invariants(std::move(invariants)), block(block) {}

    ~WhileStatement() override {
        d(imp::ast::WhileStatement) delete &condition;
        for (auto item : invariants) {
            delete item;
        }
        delete &block;
    }
};

} // namespace imp::ast

#endif // VC_GEN_IMP_HPP
