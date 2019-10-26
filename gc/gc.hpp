//  ----------------------------------------------------------------------------
//  Header file for the GC class.                                         gc.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 25, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_GC_HPP
#define VC_GEN_GC_HPP


#include "visitor.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace gc::ast {

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
        : expression(expression), BooleanExpression(Type::NotExpression) {}

    ~NotExpression() override {
        std::cout << "\n Deleting NotExpression 0x" << this << dec << "...";
        delete &expression;
    }
};

// -----------------------------------------------------------------------------
class OrExpression : public BooleanExpression {
  public:
    const BooleanExpression& left;
    const BooleanExpression& right;

    OrExpression(BooleanExpression& left, BooleanExpression& right)
        : left(left), right(right), BooleanExpression(Type::OrExpression) {}

    ~OrExpression() override {
        std::cout << "\n Deleting OrExpression 0x" << this << dec << "...";
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
        : left(left), right(right), BooleanExpression(Type::AndExpression) {}

    ~AndExpression() override {
        std::cout << "\n Deleting AndExpression 0x" << this << dec << "...";
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

    explicit Location(string identifier) : identifier(std::move(identifier)) {}

    ~Location() override {
        std::cout << "\n Deleting Location 0x" << this << dec << "...";
    }
};

// -----------------------------------------------------------------------------
class Invariant : public Node {
  public:
    const Assertion& assertion;

    explicit Invariant(Assertion& assertion) : assertion(assertion) {}

    ~Invariant() override {
        std::cout << "\n Deleting Invariant 0x" << this << dec << "...";
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
        std::cout << "\n Deleting Block 0x" << this << dec << "...";
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
        std::cout << "\n Deleting PreCondition 0x" << this << dec << "...";
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
        std::cout << "\n Deleting PostCondition 0x" << this << dec << "...";
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
        std::cout << "\n Deleting Program 0x" << this << dec << "...";
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
        : assertion(assertion), Assertion(Type::Negation) {}

    ~Negation() override {
        std::cout << "\n Deleting Negation 0x" << this << dec << "...";
        delete &assertion;
    }
};

// -----------------------------------------------------------------------------
class Disjunction : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Disjunction(Assertion& left, Assertion& right)
        : left(left), right(right), Assertion(Type::Disjunction) {}

    ~Disjunction() override {
        std::cout << "\n Deleting Disjunction 0x" << this << dec << "...";
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
        : left(left), right(right), Assertion(Type::Conjunction) {}

    ~Conjunction() override {
        std::cout << "\n Deleting Conjunction 0x" << this << dec << "...";
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
        : left(left), right(right), Assertion(Type::Implication) {}

    ~Implication() override {
        std::cout << "\n Deleting Implication 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class UniversalQuantification : public Assertion {
  public:
    const vector<string> variables;
    const Assertion& body;

    UniversalQuantification(vector<string> variables, Assertion& body)
        : variables(std::move(variables)), body(body),
          Assertion(Type::UniversalQuantification) {}

    ~UniversalQuantification() override {
        std::cout << "\n Deleting UniversalQuantification 0x" << this << dec
                  << "...";
        delete &body;
    }
};

// -----------------------------------------------------------------------------
class ExistentialQuantification : public Assertion {
  public:
    const vector<string> variables;
    const Assertion& body;

    ExistentialQuantification(vector<string> variables, Assertion& body)
        : variables(std::move(variables)), body(body),
          Assertion(Type::ExistentialQuantification) {}

    ~ExistentialQuantification() override {
        std::cout << "\n Deleting ExistentialQuantification 0x" << this << dec
                  << "...";
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
        : identifier(std::move(identifier)),
          ArithmeticExpression::ArithmeticExpression(Type::Reference) {}

    ~Reference() override {
        std::cout << "\n Deleting Reference 0x" << this << dec << "...";
    }
};

// -----------------------------------------------------------------------------
class Constant : public ArithmeticExpression {
  public:
    const int number;

    explicit Constant(const int number)
        : number(number), ArithmeticExpression(Type::Constant) {}

    ~Constant() override {
        std::cout << "\n Deleting Constant 0x" << this << dec << "...";
    }
};

// -----------------------------------------------------------------------------
class ArrayReference : public ArithmeticExpression {
  public:
    const Reference& reference;
    const ArithmeticExpression& index;

    ArrayReference(Reference& reference, ArithmeticExpression& index)
        : reference(reference), index(index),
          ArithmeticExpression(Type::ArrayReference) {}

    ~ArrayReference() override {
        std::cout << "\n Deleting ArrayReference 0x" << this << dec << "...";
        delete &index;
        delete &reference;
    }
};

// -----------------------------------------------------------------------------
class Negate : public ArithmeticExpression {
  public:
    const ArithmeticExpression& expression;

    explicit Negate(ArithmeticExpression& expression)
        : expression(expression), ArithmeticExpression(Type::Negate) {}

    ~Negate() override {
        std::cout << "\n Deleting Negate 0x" << this << dec << "...";
        delete &expression;
    }
};

// -----------------------------------------------------------------------------
class Sum : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Sum(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), ArithmeticExpression(Type::Sum) {}

    ~Sum() override {
        std::cout << "\n Deleting Sum 0x" << this << dec << "...";
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
        : left(left), right(right), ArithmeticExpression(Type::Subtract) {}

    ~Subtract() override {
        std::cout << "\n Deleting Subtract 0x" << this << dec << "...";
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
        : left(left), right(right), ArithmeticExpression(Type::Multiply) {}

    ~Multiply() override {
        std::cout << "\n Deleting Multiply 0x" << this << dec << "...";
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
        : left(left), right(right), ArithmeticExpression(Type::Divide) {}

    ~Divide() override {
        std::cout << "\n Deleting Divide 0x" << this << dec << "...";
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
        : left(left), right(right), ArithmeticExpression(Type::Mod) {}

    ~Mod() override {
        std::cout << "\n Deleting Mod 0x" << this << dec << "...";
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
        : type(type), Assertion(Assertion::Type::Comparison),
          BooleanExpression(BooleanExpression::Type::Comparison) {}
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};

// -----------------------------------------------------------------------------
class EqualComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    EqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right),
          Comparison(Comparison::Type::EqualComparison) {}

    ~EqualComparison() override {
        std::cout << "\n Deleting EqualComparison 0x" << this << dec << "...";
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
        : left(left), right(right),
          Comparison(Comparison::Type::NotEqualComparison) {}

    ~NotEqualComparison() override {
        std::cout << "\n Deleting NotEqualComparison 0x" << this << dec
                  << "...";
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
        : left(left), right(right),
          Comparison(Comparison::Type::LeqComparison) {}

    ~LeqComparison() override {
        std::cout << "\n Deleting LeqComparison 0x" << this << dec << "...";
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
        : left(left), right(right),
          Comparison(Comparison::Type::GeqComparison) {}

    ~GeqComparison() override {
        std::cout << "\n Deleting GeqComparison 0x" << this << dec << "...";
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
        : left(left), right(right), Comparison(Comparison::Type::LtComparison) {
    }

    ~LtComparison() override {
        std::cout << "\n Deleting LtComparison 0x" << this << dec << "...";
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
        : left(left), right(right), Comparison(Comparison::Type::GtComparison) {
    }

    ~GtComparison() override {
        std::cout << "\n Deleting GtComparison 0x" << this << dec << "...";
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
        : loc(loc), expr(expr),
          Statement(Statement::Type::AssignmentStatement) {}

    ~AssignmentStatement() override {
        std::cout << "\n Deleting AssignmentStatement 0x" << this << dec
                  << "...";
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
        : locFirst(locFirst), locSecond(locSecond), exprFirst(exprFirst),
          exprSecond(exprSecond),
          Statement(Statement::Type::MultipleAssignmentStatement) {}

    ~MultipleAssignmentStatement() override {
        std::cout << "\n Deleting MultipleAssignmentStatement 0x" << this << dec
                  << "...";
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
        : loc(loc), index(index), exp(exp),
          Statement(Statement::Type::ArrayAssignmentStatement) {}

    ~ArrayAssignmentStatement() override {
        std::cout << "\n Deleting ArrayAssignmentStatement 0x" << this << dec
                  << "...";
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
        : condition(condition), thenBlock(thenBlock),
          Statement(Statement::Type::IfThenStatement) {}

    ~IfThenStatement() override {
        std::cout << "\n Deleting IfThenStatement 0x" << this << dec << "...";
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
        : condition(condition), thenBlock(thenBlock), elseBlock(elseBlock),
          Statement(Statement::Type::IfThenElseStatement) {}

    ~IfThenElseStatement() override {
        std::cout << "\n Deleting IfThenElseStatement 0x" << this << dec
                  << "...";
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
        : condition(condition), invariants(std::move(invariants)), block(block),
          Statement(Statement::Type::WhileStatement) {}

    ~WhileStatement() override {
        std::cout << "\n Deleting WhileStatement 0x" << this << dec << "...";
        delete &condition;
        for (auto item : invariants) {
            delete item;
        }
        delete &block;
    }
};


} // namespace gc

#endif // VC_GEN_GC_HPP
