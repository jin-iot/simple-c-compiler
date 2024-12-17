#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include <list>
#include <ostream>
#include <optional>

namespace jincc::ast {

struct nil {};
struct unary;
struct function_call;
struct expression;

struct identifier : boost::spirit::x3::position_tagged {
    identifier(std::string const& name = "") : name(name) {}
    std::string name;
};

struct operand : boost::spirit::x3::variant<
    nil,
    bool,
    unsigned int,
    identifier,
    boost::spirit::x3::forward_ast<unary>,
    boost::spirit::x3::forward_ast<function_call>,
    boost::spirit::x3::forward_ast<expression>
> {
    using base_type::base_type;
    using base_type::operator=;
};

enum class optoken {
    plus,
    minus,
    times,
    divide,
    positive,
    negative,
    not_,
    equal,
    not_equal,
    less,
    less_equal,
    greater,
    greater_equal,
    and_,
    or_,
};

struct unary {
    optoken operator_;
    operand operand_;
};

struct operation : boost::spirit::x3::position_tagged {
    optoken operator_;
    operand operand_;
};

struct function_call : boost::spirit::x3::position_tagged {
    identifier function_name;
    std::list<expression> args;
};

struct expression : boost::spirit::x3::position_tagged {
    operand first;
    std::list<operation> rest;
};

struct assignment : boost::spirit::x3::position_tagged {
    identifier lhs;
    expression rhs;
};

struct variable_declaration {
    assignment assign;
};

struct if_statement;
struct while_statement;
struct statement_list;
struct return_statement;

struct statement : boost::spirit::x3::variant<
    variable_declaration,
    assignment,
    boost::recursive_wrapper<if_statement>,
    boost::recursive_wrapper<while_statement>,
    boost::recursive_wrapper<statement_list>
> {
    using base_type::base_type;
    using base_type::operator=;
};

struct statement_list : std::list<statement> {};

struct if_statement {
    expression condition;
    statement then;
    std::optional<statement> else_;
};

struct while_statement {
    expression condition;
    statement body;
};

struct return_statement {
    std::optional<expression> expr;
};

struct function {
    std::string return_type;
    identifier function_name;
    std::list<identifier> args;
    statement_list body;
};

inline std::ostream& operator<<(std::ostream& out, nil) {
    out << "nil";
    return out;
}

inline std::ostream& operator<<(std::ostream& out, identifier const& id) {
    out << id.name;
    return out;
}

}