//  ----------------------------------------------------------------------------
//  Declaration of AST classes.                                          ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_AST_HPP
#define VC_GEN_AST_HPP

#include "visitor.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ast {

// -----------------------------------------------------------------------------
class Node {
  public:
    Node() = default;
    virtual ~Node() = default;
    //    virtual void accept(class Visitor<Node>*) = 0;
};
ostream& operator<<(ostream& os, const Node& node);

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
    BooleanExpression(const Type type) : type(type) {}
    //    void accept(Visitor* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const BooleanExpression& expr);

// -----------------------------------------------------------------------------
class NotExpression : public BooleanExpression {
  public:
    const BooleanExpression& expression;

    explicit NotExpression(BooleanExpression& expression)
        : expression(expression), BooleanExpression(Type::NotExpression) {}

    ~NotExpression() {
        std::cout << "\n Deleting NotExpression 0x" << this << dec << "...";
        delete &expression;
    }
};
ostream& operator<<(ostream& os, const NotExpression& expression);

// -----------------------------------------------------------------------------
class OrExpression : public BooleanExpression {
  public:
    const BooleanExpression& left;
    const BooleanExpression& right;

    OrExpression(BooleanExpression& left, BooleanExpression& right)
        : left(left), right(right), BooleanExpression(Type::OrExpression) {}

    ~OrExpression() {
        std::cout << "\n Deleting OrExpression 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const OrExpression& expression);

// -----------------------------------------------------------------------------
class AndExpression : public BooleanExpression {
  public:
    const BooleanExpression& left;
    const BooleanExpression& right;

    AndExpression(BooleanExpression& left, BooleanExpression& right)
        : left(left), right(right), BooleanExpression(Type::AndExpression) {}

    ~AndExpression() {
        std::cout << "\n Deleting AndExpression 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const AndExpression& expression);

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
    Assertion(Type type) : type(type) {}
    //    void accept(Visitor* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const Assertion& assertion);

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
    Statement(Type type) : type(type) {}
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const Statement& statement);

// -----------------------------------------------------------------------------
class Location : public Node {
  public:
    const string identifier;

    explicit Location(string identifier) : identifier(std::move(identifier)) {}

    ~Location() {
        std::cout << "\n Deleting Location 0x" << this << dec << "...";
    }
};
ostream& operator<<(ostream& os, const Location& location);

// -----------------------------------------------------------------------------
class Invariant : public Node {
  public:
    const Assertion& assertion;

    explicit Invariant(Assertion& assertion) : assertion(assertion) {}

    ~Invariant() {
        std::cout << "\n Deleting Invariant 0x" << this << dec << "...";
        delete &assertion;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const Invariant& invariant);

// -----------------------------------------------------------------------------
class Block : public Node {
  public:
    vector<Statement*> stmts;

    explicit Block(vector<Statement*> stmts) : stmts(std::move(stmts)) {}

    ~Block() {
        std::cout << "\n Deleting Block 0x" << this << dec << "...";
        for (auto s : stmts)
            delete s;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const Block& block);

// -----------------------------------------------------------------------------
class PreCondition : public Node {
  public:
    const Assertion& assertion;

    explicit PreCondition(Assertion& assertion) : assertion(assertion) {}

    ~PreCondition() {
        std::cout << "\n Deleting PreCondition 0x" << this << dec << "...";
        delete &assertion;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const PreCondition& condition);

// -----------------------------------------------------------------------------
class PostCondition : public Node {
  public:
    const Assertion& assertion;

    explicit PostCondition(Assertion& assertion) : assertion(assertion) {}

    ~PostCondition() {
        std::cout << "\n Deleting PostCondition 0x" << this << dec << "...";
        delete &assertion;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const PostCondition& condition);

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

    ~Program() {
        std::cout << "\n Deleting Program 0x" << this << dec << "...";
        delete &block;
        for (auto p : preConditions)
            delete p;
        for (auto p : postConditions)
            delete p;
    }
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const Program& program);

// -----------------------------------------------------------------------------
class Negation : public Assertion {
  public:
    const Assertion& assertion;

    explicit Negation(Assertion& assertion)
        : assertion(assertion), Assertion(Type::Negation) {}

    ~Negation() {
        std::cout << "\n Deleting Negation 0x" << this << dec << "...";
        delete &assertion;
    }
};
ostream& operator<<(ostream& os, const Negation& negation);

// -----------------------------------------------------------------------------
class Disjunction : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Disjunction(Assertion& left, Assertion& right)
        : left(left), right(right), Assertion(Type::Disjunction) {}

    ~Disjunction() {
        std::cout << "\n Deleting Disjunction 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Disjunction& disjunction);

// -----------------------------------------------------------------------------
class Conjunction : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Conjunction(Assertion& left, Assertion& right)
        : left(left), right(right), Assertion(Type::Conjunction) {}

    ~Conjunction() {
        std::cout << "\n Deleting Conjunction 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Conjunction& conjunction);

// -----------------------------------------------------------------------------
class Implication : public Assertion {
  public:
    const Assertion& left;
    const Assertion& right;

    Implication(Assertion& left, Assertion& right)
        : left(left), right(right), Assertion(Type::Implication) {}

    ~Implication() {
        std::cout << "\n Deleting Implication 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Implication& implication);

// -----------------------------------------------------------------------------
class UniversalQuantification : public Assertion {
  public:
    const vector<string> variables;
    const Assertion& body;

    UniversalQuantification(vector<string> variables, Assertion& body)
        : variables(std::move(variables)), body(body),
          Assertion(Type::UniversalQuantification) {}

    ~UniversalQuantification() {
        std::cout << "\n Deleting UniversalQuantification 0x" << this << dec
                  << "...";
        delete &body;
    }
};
ostream& operator<<(ostream& os, const UniversalQuantification& quant);

// -----------------------------------------------------------------------------
class ExistentialQuantification : public Assertion {
  public:
    const vector<string> variables;
    const Assertion& body;

    ExistentialQuantification(vector<string> variables, Assertion& body)
        : variables(std::move(variables)), body(body),
          Assertion(Type::ExistentialQuantification) {}

    ~ExistentialQuantification() {
        std::cout << "\n Deleting ExistentialQuantification 0x" << this << dec
                  << "...";
        delete &body;
    }
};
ostream& operator<<(ostream& os, const ExistentialQuantification& q);

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
    ArithmeticExpression(Type type) : type(type) {}
    //    void accept(Visitor* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const ArithmeticExpression& e);

// -----------------------------------------------------------------------------
class Reference : public ArithmeticExpression {
  public:
    const string identifier;

    explicit Reference(string identifier)
        : identifier(std::move(identifier)),
          ArithmeticExpression::ArithmeticExpression(Type::Reference) {}

    ~Reference() {
        std::cout << "\n Deleting Reference 0x" << this << dec << "...";
    }
};
ostream& operator<<(ostream& os, const Reference& reference);

// -----------------------------------------------------------------------------
class Constant : public ArithmeticExpression {
  public:
    const int number;

    explicit Constant(const int number)
        : number(number), ArithmeticExpression(Type::Constant) {}

    ~Constant() {
        std::cout << "\n Deleting Constant 0x" << this << dec << "...";
    }
};
ostream& operator<<(ostream& os, const Constant& constant);

// -----------------------------------------------------------------------------
class ArrayReference : public ArithmeticExpression {
  public:
    const Reference& reference;
    const ArithmeticExpression& index;

    ArrayReference(Reference& reference, ArithmeticExpression& index)
        : reference(reference), index(index),
          ArithmeticExpression(Type::ArrayReference) {}

    ~ArrayReference() {
        std::cout << "\n Deleting ArrayReference 0x" << this << dec << "...";
        delete &index;
        delete &reference;
    }
};
ostream& operator<<(ostream& os, const ArrayReference& reference);

// -----------------------------------------------------------------------------
class Negate : public ArithmeticExpression {
  public:
    const ArithmeticExpression& expression;

    explicit Negate(ArithmeticExpression& expression)
        : expression(expression), ArithmeticExpression(Type::Negate) {}

    ~Negate() {
        std::cout << "\n Deleting Negate 0x" << this << dec << "...";
        delete &expression;
    }
};
ostream& operator<<(ostream& os, const Negate& negate);

// -----------------------------------------------------------------------------
class Sum : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Sum(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), ArithmeticExpression(Type::Sum) {}

    ~Sum() {
        std::cout << "\n Deleting Sum 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Sum& sum);

// -----------------------------------------------------------------------------
class Subtract : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Subtract(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), ArithmeticExpression(Type::Subtract) {}

    ~Subtract() {
        std::cout << "\n Deleting Subtract 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Subtract& subtract);

// -----------------------------------------------------------------------------
class Multiply : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Multiply(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), ArithmeticExpression(Type::Multiply) {}

    ~Multiply() {
        std::cout << "\n Deleting Multiply 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Multiply& multiply);

// -----------------------------------------------------------------------------
class Divide : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Divide(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), ArithmeticExpression(Type::Divide) {}

    ~Divide() {
        std::cout << "\n Deleting Divide 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Divide& divide);

// -----------------------------------------------------------------------------
class Mod : public ArithmeticExpression {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    Mod(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), ArithmeticExpression(Type::Mod) {}

    ~Mod() {
        std::cout << "\n Deleting Mod 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const Mod& mod);

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

    Comparison(Comparison::Type type)
        : type(type), Assertion(Assertion::Type::Comparison),
          BooleanExpression(BooleanExpression::Type::Comparison) {}
    //    void accept(Visitor<Node>* v) { v->visit(this); }
};
ostream& operator<<(ostream& os, const Comparison& comparison);

// -----------------------------------------------------------------------------
class EqualComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    EqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right),
          Comparison(Comparison::Type::EqualComparison) {}

    ~EqualComparison() {
        std::cout << "\n Deleting EqualComparison 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const EqualComparison& comparison);

// -----------------------------------------------------------------------------
class NotEqualComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    NotEqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right),
          Comparison(Comparison::Type::NotEqualComparison) {}

    ~NotEqualComparison() {
        std::cout << "\n Deleting NotEqualComparison 0x" << this << dec
                  << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const NotEqualComparison& comparison);

// -----------------------------------------------------------------------------
class LeqComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    LeqComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right),
          Comparison(Comparison::Type::LeqComparison) {}

    ~LeqComparison() {
        std::cout << "\n Deleting LeqComparison 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const LeqComparison& comparison);

// -----------------------------------------------------------------------------
class GeqComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    GeqComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right),
          Comparison(Comparison::Type::GeqComparison) {}

    ~GeqComparison() {
        std::cout << "\n Deleting GeqComparison 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const GeqComparison& comparison);

// -----------------------------------------------------------------------------
class LtComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    LtComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), Comparison(Comparison::Type::LtComparison) {
    }

    ~LtComparison() {
        std::cout << "\n Deleting LtComparison 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const LtComparison& comparison);

// -----------------------------------------------------------------------------
class GtComparison : public Comparison {
  public:
    const ArithmeticExpression& left;
    const ArithmeticExpression& right;

    GtComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right), Comparison(Comparison::Type::GtComparison) {
    }

    ~GtComparison() {
        std::cout << "\n Deleting GtComparison 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};
ostream& operator<<(ostream& os, const GtComparison& comparison);

// -----------------------------------------------------------------------------
class AssignmentStatement : public Statement {
  public:
    const Location& loc;
    const ArithmeticExpression& expr;

    AssignmentStatement(Location& loc, ArithmeticExpression& expr)
        : loc(loc), expr(expr),
          Statement(Statement::Type::AssignmentStatement) {}

    ~AssignmentStatement() {
        std::cout << "\n Deleting AssignmentStatement 0x" << this << dec
                  << "...";
        delete &loc;
        delete &expr;
    }
};
ostream& operator<<(ostream& os, const AssignmentStatement& s);

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

    ~MultipleAssignmentStatement() {
        std::cout << "\n Deleting MultipleAssignmentStatement 0x" << this << dec
                  << "...";
        delete &locFirst;
        delete &locSecond;
        delete &exprFirst;
        delete &exprSecond;
    }
};
ostream& operator<<(ostream& os, const MultipleAssignmentStatement& s);

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

    ~ArrayAssignmentStatement() {
        std::cout << "\n Deleting ArrayAssignmentStatement 0x" << this << dec
                  << "...";
        delete &loc;
        delete &index;
        delete &exp;
    }
};
ostream& operator<<(ostream& os, const ArrayAssignmentStatement& s);

// -----------------------------------------------------------------------------
class IfThenStatement : public Statement {
  public:
    const BooleanExpression& condition;
    const Block& thenBlock;

    IfThenStatement(BooleanExpression& condition, Block& thenBlock)
        : condition(condition), thenBlock(thenBlock),
          Statement(Statement::Type::IfThenStatement) {}

    ~IfThenStatement() {
        std::cout << "\n Deleting IfThenStatement 0x" << this << dec << "...";
        delete &condition;
        delete &thenBlock;
    }
};
ostream& operator<<(ostream& os, const IfThenStatement& statement);

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

    ~IfThenElseStatement() {
        std::cout << "\n Deleting IfThenElseStatement 0x" << this << dec
                  << "...";
        delete &condition;
        delete &thenBlock;
        delete &elseBlock;
    }
};
ostream& operator<<(ostream& os, const IfThenElseStatement& s);

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

    ~WhileStatement() {
        std::cout << "\n Deleting WhileStatement 0x" << this << dec << "...";
        delete &condition;
        for (auto item : invariants) {
            delete item;
        }
        delete &block;
    }
};
ostream& operator<<(ostream& os, const WhileStatement& statement);

} // namespace ast

#endif // VC_GEN_AST_HPP
