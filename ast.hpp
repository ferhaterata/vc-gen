//  ----------------------------------------------------------------------------
//  Declaration of AST classes.                                          ast.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 23, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_AST_HPP
#define VC_GEN_AST_HPP

#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace ast {

class Node {
  public:
    Node() {}
    virtual ~Node() = default;
};

class ArithmeticExpression : public Node {};
class Comparison : public Node {};
class BooleanExpression : public Node {};
class Statement : public Node {};
class Invariant : public Node {};
class Block : public Node {};
class Program : public Node {};
class Precondition : public Node {};
class PostCondition : public Node {};
class Identifier : public Node {};

class AssignmentStatement : public Statement {
  public:
    const ArithmeticExpression* condition;
    const Identifier* location;
    AssignmentStatement(ArithmeticExpression* condition, Identifier* location)
        : condition(condition), location(location) {}
};

class MultipleAssignmentStatement : public Statement {
  public:
    const map<Identifier, ArithmeticExpression> assignments;
};

class ArrayAssignmentStatement : public Statement {
  public:
    const ArithmeticExpression* condition;
    const ArithmeticExpression* index;
    const Identifier* location;
    ArrayAssignmentStatement(ArithmeticExpression* condition,
                             ArithmeticExpression* index, Identifier* location)
        : condition(condition), index(index), location(location) {}
};

class IfThenStatement : public Statement {
  public:
    const BooleanExpression* condition;
    const Block* thenBlock;
    IfThenStatement(BooleanExpression* condition, Block* thenBlock)
        : condition(condition), thenBlock(thenBlock) {}
};

class IfThenElseStatement : public Statement {
  public:
    const BooleanExpression* condition;
    const Block* thenBlock;
    const Block* elseBlock;
    IfThenElseStatement(BooleanExpression* condition, Block* thenBlock,
                        Block* elseBlock)
        : condition(condition), thenBlock(thenBlock), elseBlock(elseBlock) {}
};

class WhileStatement : public Statement {
  public:
    const BooleanExpression* condition;
    const vector<Invariant> invariants;
    const Block* block;
    WhileStatement(BooleanExpression* condition, vector<Invariant> invariants,
                   Block* block)
        : condition(condition), invariants(std::move(invariants)),
          block(block) {}
};

} // namespace ast

#endif // VC_GEN_AST_HPP
