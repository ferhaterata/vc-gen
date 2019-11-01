//  ----------------------------------------------------------------------------
//  Declaration and Definition of AST classes.                           ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_IMP_HPP
#define VC_GEN_IMP_HPP

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
    //    virtual void accept(class Visitor<Node>*) = 0;
};

// -----------------------------------------------------------------------------
class BooleanExpression : public Node {
  public:
    enum class Type {
        NotExpression,
        OrExpression,
        AndExpression,
        Comparison,
    };
    const Type type;
    explicit BooleanExpression(const Type type) : type(type) {}
    //    void accept(Visitor* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class NotExpression : public BooleanExpression {
  public:
    const BooleanExpression& expression;

    explicit NotExpression(BooleanExpression& expression)
        : BooleanExpression(Type::NotExpression), expression(expression) {}

    ~NotExpression() override {
        std::cout << "Deleting NotExpression 0x" << this << dec << "...\n";
        delete &expression;
    }
};

// -----------------------------------------------------------------------------
class OrExpression : public BooleanExpression {
  public:
    const BooleanExpression& left;
    const BooleanExpression& right;

    OrExpression(BooleanExpression& left, BooleanExpression& right)
        : BooleanExpression(Type::OrExpression), left(left), right(right) {}

    ~OrExpression() override {
        std::cout << "Deleting OrExpression 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting AndExpression 0x" << this << dec << "...\n";
        delete &left;
        delete &right;
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
    };
    const Type type;
    explicit Assertion(Type type) : type(type) {}
    //    void accept(Visitor* v) { v->visit(this); }
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
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class Location : public Node {
  public:
    const string identifier;
    const string fresh;

    explicit Location(string identifier, string fresh)
        : identifier(std::move(identifier)), fresh(std::move(fresh)) {}

    ~Location() override {
        std::cout << "Deleting Location 0x" << this << dec << "...\n";
    }
};

// -----------------------------------------------------------------------------
class Invariant : public Node {
  public:
    const Assertion& assertion;

    explicit Invariant(Assertion& assertion) : assertion(assertion) {}

    ~Invariant() override {
        std::cout << "Deleting Invariant 0x" << this << dec << "...\n";
        delete &assertion;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class Block : public Node {
  public:
    vector<Statement*> stmts;

    explicit Block(vector<Statement*> stmts) : stmts(std::move(stmts)) {}

    ~Block() override {
        std::cout << "Deleting Block 0x" << this << dec << "...\n";
        for (auto s : stmts)
            delete s;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class PreCondition : public Node {
  public:
    const Assertion& assertion;

    explicit PreCondition(Assertion& assertion) : assertion(assertion) {}

    ~PreCondition() override {
        std::cout << "Deleting PreCondition 0x" << this << dec << "...\n";
        delete &assertion;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class PostCondition : public Node {
  public:
    const Assertion& assertion;

    explicit PostCondition(Assertion& assertion) : assertion(assertion) {}

    ~PostCondition() override {
        std::cout << "Deleting PostCondition 0x" << this << dec << "...\n";
        delete &assertion;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
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
        std::cout << "Deleting Program 0x" << this << dec << "...\n";
        delete &block;
        for (auto p : preConditions)
            delete p;
        for (auto p : postConditions)
            delete p;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class Negation : public Assertion {
  public:
    const Assertion& assertion;

    explicit Negation(Assertion& assertion)
        : Assertion(Type::Negation), assertion(assertion) {}

    ~Negation() override {
        std::cout << "Deleting Negation 0x" << this << dec << "...\n";
        delete &assertion;
    }
};

// -----------------------------------------------------------------------------
class Disjunction : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Disjunction(Assertion& left, Assertion& right)
        : Assertion(Type::Disjunction), left(left), right(right) {}

    ~Disjunction() override {
        std::cout << "Deleting Disjunction 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting Conjunction 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting Implication 0x" << this << dec << "...\n";
        delete &left;
        delete &right;
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
        std::cout << "Deleting UniversalQuantifier 0x" << this << dec
                  << "...\n";
        delete &body;
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
        std::cout << "Deleting ExistentialQuantifier 0x" << this << dec
                  << "...\n";
        delete &body;
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
    };
    Type type;
    explicit ArithmeticExpression(Type type) : type(type) {}
    //    void accept(Visitor* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class Reference : public ArithmeticExpression {
  public:
    const string identifier;

    explicit Reference(string identifier)
        : ArithmeticExpression::ArithmeticExpression(Type::Reference),
          identifier(std::move(identifier)) {}

    ~Reference() override {
        std::cout << "Deleting Reference 0x" << this << dec << "...\n";
    }
};

// -----------------------------------------------------------------------------
class Constant : public ArithmeticExpression {
  public:
    const int number;

    explicit Constant(const int number)
        : ArithmeticExpression(Type::Constant), number(number) {}

    ~Constant() override {
        std::cout << "Deleting Constant 0x" << this << dec << "...\n";
    }
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
        std::cout << "Deleting ArrayReference 0x" << this << dec << "...\n";
        delete &index;
        delete &reference;
    }
};

// -----------------------------------------------------------------------------
class Negate : public ArithmeticExpression {
  public:
    const ArithmeticExpression& expression;

    explicit Negate(ArithmeticExpression& expression)
        : ArithmeticExpression(Type::Negate), expression(expression) {}

    ~Negate() override {
        std::cout << "Deleting Negate 0x" << this << dec << "...\n";
        delete &expression;
    }
};

// -----------------------------------------------------------------------------
class Sum : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Sum(ArithmeticExpression& left, ArithmeticExpression& right)
        : ArithmeticExpression(Type::Sum), left(left), right(right) {}

    ~Sum() override {
        std::cout << "Deleting Sum 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting Subtract 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting Multiply 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting Divide 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting Mod 0x" << this << dec << "...\n";
        delete &left;
        delete &right;
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
    //    void accept(Visitor<Node>* v) { v->visit(this); }
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
        std::cout << "Deleting EqualComparison 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting NotEqualComparison 0x" << this << dec
                  << "...\n";
        delete &left;
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
        std::cout << "Deleting LeqComparison 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting GeqComparison 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting LtComparison 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting GtComparison 0x" << this << dec << "...\n";
        delete &left;
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
        std::cout << "Deleting AssignmentStatement 0x" << this << dec
                  << "...\n";
        delete &loc;
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
        std::cout << "Deleting MultipleAssignmentStatement 0x" << this << dec
                  << "...\n";
        delete &locFirst;
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
        std::cout << "Deleting ArrayAssignmentStatement 0x" << this << dec
                  << "...\n";
        delete &loc;
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
        std::cout << "Deleting IfThenStatement 0x" << this << dec << "...\n";
        delete &condition;
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
        std::cout << "Deleting IfThenElseStatement 0x" << this << dec
                  << "...\n";
        delete &condition;
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
        std::cout << "Deleting WhileStatement 0x" << this << dec << "...\n";
        delete &condition;
        for (auto item : invariants) {
            delete item;
        }
        delete &block;
    }
};

} // namespace imp::ast

#endif // VC_GEN_IMP_HPP
