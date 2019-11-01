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
        Select,
        List,
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
        //        std::cout << " Deleting Location 0x" << this << dec <<
        //        "...\n";
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

    explicit Assume(const Assertion& assertion)
        : Command(Command::Type::Assume), assertion(assertion) {}

    ~Assume() override {
        //        std::cout << " Deleting Assume 0x" << this << dec << "...\n";
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
        //        std::cout << " Deleting Assert 0x" << this << dec << "...\n";
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
        //        std::cout << " Deleting Havoc 0x" << this << dec << "...\n";
        delete &location;
    }
};

// -----------------------------------------------------------------------------
class Select : public Command {

  public:
    vector<Command*> left;
    vector<Command*> right;
    vector<Command*> leftExt;  // no custody
    vector<Command*> rightExt; // no custody

    Select(vector<Command*> left, vector<Command*> right)
        : Command(Command::Type::Select), left(std::move(left)),
          right(std::move(right)) {}

    ~Select() override {
        //        std::cout << " Deleting Select 0x" << this << dec << "...\n";
        for (auto c : left) {
            delete c;
        }
        for (auto c : right) {
            delete c;
        }
    }
};

// -----------------------------------------------------------------------------
class List : public Command {
  public:
    vector<Command*> commands;

    explicit List(vector<Command*> commands)
        : Command(Command::Type::List), commands(std::move(commands)) {}

    ~List() override {
        //        std::cout << " Deleting Command List 0x" << this << dec <<
        //        "...\n";
        for (auto c : commands) {
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
        //        std::cout << " Deleting Program 0x" << this << dec << "...\n";
        for (auto c : commands)
            delete c;
    }
};

// -----------------------------------------------------------------------------
class Negation : public Assertion {
  public:
    const Assertion& assertion;

    explicit Negation(Assertion& assertion)
        : Assertion(Type::Negation), assertion(assertion) {}

    ~Negation() override {
        //        std::cout << " Deleting Negation 0x" << this << dec <<
        //        "...\n";
        delete &assertion;
    }
};

// -----------------------------------------------------------------------------
class True : public Assertion {
  public:
    True() : Assertion(Assertion::Type::True) {}
    ~True() override {
        //        std::cout << " Deleting True 0x" << this << dec << "...\n";
    }
};

// -----------------------------------------------------------------------------
class False : public Assertion {
  public:
    False() : Assertion(Assertion::Type::False) {}

    ~False() override {
        //        std::cout << " Deleting False 0x" << this << dec << "...\n";
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
        //        std::cout << " Deleting Disjunction 0x" << this << dec <<
        //        "...\n";
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
        //        std::cout << " Deleting Conjunction 0x" << this << dec <<
        //        "...\n";
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
        //        std::cout << " Deleting Implication 0x" << this << dec <<
        //        "...\n";
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
        //        std::cout << " Deleting UniversalQuantifier 0x" << this << dec
        //                  << "...\n";
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
        //        std::cout << " Deleting ExistentialQuantifier 0x" << this <<
        //        dec
        //                  << "...\n";
        delete &body;
    }
};

// -----------------------------------------------------------------------------
class Constant : public Expression {
  public:
    const int number;

    explicit Constant(const int number)
        : Expression(Type::Constant), number(number) {}

    ~Constant() override {
        //        std::cout << " Deleting Constant 0x" << this << dec <<
        //        "...\n";
    }
};

// -----------------------------------------------------------------------------
class ArrayLocation : public Expression {
  public:
    const Location& location;
    const Expression& index;

    ArrayLocation(Location& location, Expression& index)
        : Expression(Type::ArrayLocation), location(location), index(index) {}

    ~ArrayLocation() override {
        //        std::cout << " Deleting ArrayLocation 0x" << this << dec <<
        //        "...\n";
        delete &index;
        delete &location;
    }
};

// -----------------------------------------------------------------------------
class Negate : public Expression {
  public:
    const Expression& expression;

    explicit Negate(Expression& expression)
        : Expression(Type::Negate), expression(expression) {}

    ~Negate() override {
        //        std::cout << " Deleting Negate 0x" << this << dec << "...\n";
        delete &expression;
    }
};

// -----------------------------------------------------------------------------
class Sum : public Expression {
  public:
    const Expression& left;
    const Expression& right;

    Sum(Expression& left, Expression& right)
        : Expression(Type::Sum), left(left), right(right) {}

    ~Sum() override {
        //        std::cout << " Deleting Sum 0x" << this << dec << "...\n";
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
        : Expression(Type::Subtract), left(left), right(right) {}

    ~Subtract() override {
        //        std::cout << " Deleting Subtract 0x" << this << dec <<
        //        "...\n";
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
        : Expression(Type::Multiply), left(left), right(right) {}

    ~Multiply() override {
        //        std::cout << " Deleting Multiply 0x" << this << dec <<
        //        "...\n";
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
        : Expression(Type::Divide), left(left), right(right) {}

    ~Divide() override {
        //        std::cout << " Deleting Divide 0x" << this << dec << "...\n";
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
        : Expression(Type::Mod), left(left), right(right) {}

    ~Mod() override {
        //        std::cout << " Deleting Mod 0x" << this << dec << "...\n";
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
        : Assertion(Assertion::Type::Comparison), type(type) {}
};

// -----------------------------------------------------------------------------
class EqualComparison : public Comparison {
  public:
    const Expression& left;
    const Expression& right;

    EqualComparison(Expression& left, Expression& right)
        : Comparison(Comparison::Type::EqualComparison), left(left),
          right(right) {}

    ~EqualComparison() override {
        //        std::cout << " Deleting EqualComparison 0x" << this << dec <<
        //        "...\n";
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
        : Comparison(Comparison::Type::NotEqualComparison), left(left),
          right(right) {}

    ~NotEqualComparison() override {
        //        std::cout << " Deleting NotEqualComparison 0x" << this << dec
        //                  << "...\n";
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
        : Comparison(Comparison::Type::LeqComparison), left(left),
          right(right) {}

    ~LeqComparison() override {
        //        std::cout << " Deleting LeqComparison 0x" << this << dec <<
        //        "...\n";
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
        : Comparison(Comparison::Type::GeqComparison), left(left),
          right(right) {}

    ~GeqComparison() override {
        //        std::cout << " Deleting GeqComparison 0x" << this << dec <<
        //        "...\n";
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
        : Comparison(Comparison::Type::LtComparison), left(left), right(right) {
    }

    ~LtComparison() override {
        //        std::cout << " Deleting LtComparison 0x" << this << dec <<
        //        "...\n";
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
        : Comparison(Comparison::Type::GtComparison), left(left), right(right) {
    }

    ~GtComparison() override {
        //        std::cout << " Deleting GtComparison 0x" << this << dec <<
        //        "...\n";
        delete &left;
        delete &right;
    }
};

} // namespace gc::ast

#endif // VC_GEN_GC_HPP
