//  ----------------------------------------------------------------------------
//  Header file for the GC class.                                         gc.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on October 25, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef VC_GEN_GC_HPP
#define VC_GEN_GC_HPP

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace gc::ast {

// -----------------------------------------------------------------------------
class Node {
  public:
    Node() = default;
    virtual ~Node() = default;
};

// -----------------------------------------------------------------------------
class Command : public Node {
  public:
    enum class Type {
        Assume,
        Assert,
        Havoc,
        Choice,
    };
    const Type type;

    explicit Command(const Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class Expression : public Node {

  public:
    enum class Type {
        ArrayLocation,
        Constant,
        Negate,
        Sum,
        Subtract,
        Multiply,
        Divide,
        Mod,
        Location,
    };
    Type type;
    explicit Expression(Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class Location : public Expression {
  public:
    const string identifier;

    explicit Location(string identifier)
        : Expression(Expression::Type::Location),
          identifier(std::move(identifier)) {}

    ~Location() override {
        std::cout << "\n Deleting Location 0x" << this << dec << "...";
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
        True,
        False,
    };
    const Type type;
    explicit Assertion(Type type) : type(type) {}
};

// -----------------------------------------------------------------------------
class Assume : public Command {
  public:
    const Assertion& assertion;

    explicit Assume(Assertion& assertion)
        : Command(Command::Type::Assume), assertion(assertion) {}

    ~Assume() override {
        std::cout << "\n Deleting Assume 0x" << this << dec << "...";
        delete &assertion;
    }
};

// -----------------------------------------------------------------------------
class Assert : public Command {
  public:
    const Assertion& assertion;

    explicit Assert(const Assertion& assertion)
        : Command(Command::Type::Assert), assertion(assertion) {}

    ~Assert() override {
        std::cout << "\n Deleting Assert 0x" << this << dec << "...";
        delete &assertion;
    }
};

// -----------------------------------------------------------------------------
class Havoc : public Command {
  public:
    const Location& location;

    explicit Havoc(const Location& location)
        : Command(Command::Type::Havoc), location(location) {}

    ~Havoc() override {
        std::cout << "\n Deleting Havoc 0x" << this << dec << "...";
        delete &location;
    }
};

// -----------------------------------------------------------------------------
class Choice : public Command {

  public:
    const vector<Command*> left;
    const vector<Command*> right;

    Choice(vector<Command*> left, vector<Command*> right)
        : Command(Command::Type::Choice), left(std::move(left)),
          right(std::move(right)) {}

    ~Choice() override {
        std::cout << "\n Deleting Choice 0x" << this << dec << "...";
        for (auto c : left) {
            delete c;
        }
        for (auto c : right) {
            delete c;
        }
    }
};

// -----------------------------------------------------------------------------
class Program : public Node {
  public:
    const vector<Command*> commands;

    explicit Program(vector<Command*> commands)
        : commands(std::move(commands)) {}

    ~Program() override {
        std::cout << "\n Deleting Program 0x" << this << dec << "...";
        for (auto c : commands)
            delete c;
    }
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
class True : public Assertion {
  public:
    True() : Assertion(Assertion::Type::True) {}
    ~True() override {
        std::cout << "\n Deleting True 0x" << this << dec << "...";
    }
};

// -----------------------------------------------------------------------------
class False : public Assertion {
  public:
    False() : Assertion(Assertion::Type::False) {}

    ~False() override {
        std::cout << "\n Deleting False 0x" << this << dec << "...";
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
class Constant : public Expression {
  public:
    const int number;

    explicit Constant(const int number)
        : number(number), Expression(Type::Constant) {}

    ~Constant() override {
        std::cout << "\n Deleting Constant 0x" << this << dec << "...";
    }
};

// -----------------------------------------------------------------------------
class ArrayLocation : public Expression {
  public:
    const Location& location;
    const Expression& index;

    ArrayLocation(Location& location, Expression& index)
        : location(location), index(index), Expression(Type::ArrayLocation) {}

    ~ArrayLocation() override {
        std::cout << "\n Deleting ArrayLocation 0x" << this << dec << "...";
        delete &index;
        delete &location;
    }
};

// -----------------------------------------------------------------------------
class Negate : public Expression {
  public:
    const Expression& expression;

    explicit Negate(Expression& expression)
        : expression(expression), Expression(Type::Negate) {}

    ~Negate() override {
        std::cout << "\n Deleting Negate 0x" << this << dec << "...";
        delete &expression;
    }
};

// -----------------------------------------------------------------------------
class Sum : public Expression {
  public:
    const Expression& left;
    const Expression& right;

    Sum(Expression& left, Expression& right)
        : left(left), right(right), Expression(Type::Sum) {}

    ~Sum() override {
        std::cout << "\n Deleting Sum 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Subtract : public Expression {
  public:
    const Expression& left;
    const Expression& right;

    Subtract(Expression& left, Expression& right)
        : left(left), right(right), Expression(Type::Subtract) {}

    ~Subtract() override {
        std::cout << "\n Deleting Subtract 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Multiply : public Expression {
  public:
    const Expression& left;
    const Expression& right;

    Multiply(Expression& left, Expression& right)
        : left(left), right(right), Expression(Type::Multiply) {}

    ~Multiply() override {
        std::cout << "\n Deleting Multiply 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Divide : public Expression {
  public:
    const Expression& left;
    const Expression& right;

    Divide(Expression& left, Expression& right)
        : left(left), right(right), Expression(Type::Divide) {}

    ~Divide() override {
        std::cout << "\n Deleting Divide 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Mod : public Expression {
  public:
    const Expression& left;
    const Expression& right;

    Mod(Expression& left, Expression& right)
        : left(left), right(right), Expression(Type::Mod) {}

    ~Mod() override {
        std::cout << "\n Deleting Mod 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

// -----------------------------------------------------------------------------
class Comparison : public Assertion {
  public:
    enum class Type {
        EqualComparison,
        NotEqualComparison,
        LeqComparison,
        GeqComparison,
        LtComparison,
        GtComparison,
    };
    const Type type;

    explicit Comparison(Comparison::Type type)
        : type(type), Assertion(Assertion::Type::Comparison) {}
};

// -----------------------------------------------------------------------------
class EqualComparison : public Comparison {
  public:
    const Expression& left;
    const Expression& right;

    EqualComparison(Expression& left, Expression& right)
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
    const Expression& left;
    const Expression& right;

    NotEqualComparison(Expression& left, Expression& right)
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
    const Expression& left;
    const Expression& right;

    LeqComparison(Expression& left, Expression& right)
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
    const Expression& left;
    const Expression& right;

    GeqComparison(Expression& left, Expression& right)
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
    const Expression& left;
    const Expression& right;

    LtComparison(Expression& left, Expression& right)
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
    const Expression& left;
    const Expression& right;

    GtComparison(Expression& left, Expression& right)
        : left(left), right(right), Comparison(Comparison::Type::GtComparison) {
    }

    ~GtComparison() override {
        std::cout << "\n Deleting GtComparison 0x" << this << dec << "...";
        delete &left;
        delete &right;
    }
};

} // namespace gc::ast

#endif // VC_GEN_GC_HPP
