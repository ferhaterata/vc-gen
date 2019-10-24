//  ----------------------------------------------------------------------------
//  Declaration of AST classes.                                          ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_AST_HPP
#define VC_GEN_AST_HPP

#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ast {

class Node {
  public:
    Node() = default;
    virtual ~Node() = default;
    //    virtual ostream& print(ostream& out) const = 0;
};

class BooleanExpression : public Node {};
class Assertion : public Node {};
class Comparison : public BooleanExpression, public Assertion {};

class Statement : public Node {};

class Location : public Statement {
  public:
    string identifier;
    Location() = default;
    explicit Location(string& identifier) : identifier(identifier) {}
};

class Invariant : public Node {
  public:
    Assertion assertion;
    Invariant() = default;
    ;
    explicit Invariant(Assertion& assertion) : assertion(assertion) {}
};

class Block : public Node {
  public:
    vector<Statement> stmts;
    Block() = default;
    explicit Block(vector<Statement>& stmts) : stmts(stmts) {}
};

class PreCondition : public Node {
  public:
    Assertion assertion;
    PreCondition() = default;
    explicit PreCondition(Assertion& assertion) : assertion(assertion) {}
};

class PostCondition : public Node {
  public:
    Assertion assertion;
    PostCondition() = default;
    ;
    explicit PostCondition(Assertion& assertion) : assertion(assertion) {}
};

class Program : public Node {
    string identifier;
    vector<PreCondition> preConditions;
    vector<PostCondition> postConditions;
    Block block;

  public:
    Program() = default;
    Program(string& identifier, vector<PreCondition>& preConditions,
            vector<PostCondition>& postConditions, Block& block)
        : identifier(identifier), preConditions(preConditions),
          postConditions(postConditions), block(block) {}
};

class Negation : public Assertion {
  public:
    const Assertion assertion;
    Negation(Assertion& assertion) : assertion(assertion) {}
};

class Disjunction : public Assertion {
  public:
    const Assertion left;
    const Assertion right;
    Disjunction(Assertion& left, Assertion& right) : left(left), right(right) {}
};

class Conjunction : public Assertion {
  public:
    const Assertion left;
    const Assertion right;
    Conjunction(Assertion& left, Assertion& right) : left(left), right(right) {}
};

class Implication : public Assertion {
  public:
    const Assertion left;
    const Assertion right;
    Implication(Assertion& left, Assertion& right) : left(left), right(right) {}
};

class UniversalQuantification : public Assertion {
  public:
    const vector<string> variables;
    const Assertion body;
    UniversalQuantification(vector<string>& variables, Assertion& body)
        : variables(variables), body(body) {}
};

class ExistentialQuantification : public Assertion {
  public:
    const vector<string> variables;
    const Assertion body;
    ExistentialQuantification(vector<string>& variables, Assertion& body)
        : variables(variables), body(body) {}
};

class ArithmeticExpression : public Node {
    //    ostream& print(ostream& out);
};

class Reference : public ArithmeticExpression {
  public:
    string identifier;
    Reference() = default;
    explicit Reference(string& identifier) : identifier(identifier) {}
};

class EqualComparison : public Comparison {
  public:
    const ArithmeticExpression left;
    const ArithmeticExpression right;
    EqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right) {}
};

class NotEqualComparison : public Comparison {
  public:
    const ArithmeticExpression left;
    const ArithmeticExpression right;
    NotEqualComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right) {}
};

class LeqComparison : public Comparison {
  public:
    const ArithmeticExpression left;
    const ArithmeticExpression right;
    LeqComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right) {}
};

class GeqComparison : public Comparison {
  public:
    const ArithmeticExpression left;
    const ArithmeticExpression right;
    GeqComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right) {}
};

class LtComparison : public Comparison {
  public:
    const ArithmeticExpression left;
    const ArithmeticExpression right;
    LtComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right) {}
};

class GtComparison : public Comparison {
  public:
    const ArithmeticExpression left;
    const ArithmeticExpression right;
    GtComparison(ArithmeticExpression& left, ArithmeticExpression& right)
        : left(left), right(right) {}
};

class AssignmentStatement : public Statement {
  public:
    const Location loc;
    const ArithmeticExpression expr;
    AssignmentStatement(Location& loc, ArithmeticExpression& expr)
        : loc(loc), expr(expr) {}
};

class MultipleAssignmentStatement : public Statement {
  public:
    const Location locFirst;
    const Location locSecond;
    const ArithmeticExpression exprFirst;
    const ArithmeticExpression exprSecond;
    MultipleAssignmentStatement(Location& locFirst, Location& locSecond,
                                ArithmeticExpression& exprFirst,
                                ArithmeticExpression& exprSecond)
        : locFirst(locFirst), locSecond(locSecond), exprFirst(exprFirst),
          exprSecond(exprSecond) {}
};

class ArrayAssignmentStatement : public Statement {
  public:
    const Location loc;
    const ArithmeticExpression index;
    const ArithmeticExpression exp;
    ArrayAssignmentStatement(Location& loc, ArithmeticExpression& index,
                             ArithmeticExpression& exp)
        : loc(loc), index(index), exp(exp) {}
};

class IfThenStatement : public Statement {
  public:
    const BooleanExpression exp;
    const Block thenBlock;
    IfThenStatement(BooleanExpression& exp, Block& thenBlock)
        : exp(exp), thenBlock(thenBlock) {}
};

class IfThenElseStatement : public Statement {
  public:
    const BooleanExpression condition;
    const Block thenBlock;
    const Block elseBlock;
    IfThenElseStatement(BooleanExpression& condition, Block& thenBlock,
                        Block& elseBlock)
        : condition(condition), thenBlock(thenBlock), elseBlock(elseBlock) {}
};

class WhileStatement : public Statement {
  public:
    const BooleanExpression condition;
    const vector<Invariant> invariants;
    const Block block;
    WhileStatement(BooleanExpression& condition, vector<Invariant> invariants,
                   Block& block)
        : condition(condition), invariants(std::move(invariants)),
          block(block) {}
};

} // namespace ast

// inline ostream& operator<<(ostream& out, ast::Node& node) {
//    return node.print(out);
//}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

#endif // VC_GEN_AST_HPP
