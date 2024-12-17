#pragma once

#include "ast.hpp"
#include "ast_adapted.hpp"
#include "expression.hpp"
#include "common.hpp"
#include "error_handler.hpp"

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/annotate_on_success.hpp>

namespace jincc::parser {

using boost::spirit::x3::uint_;
using boost::spirit::x3::char_;
using boost::spirit::x3::bool_;
using boost::spirit::x3::raw;
using boost::spirit::x3::lexeme;
using namespace boost::spirit::x3::ascii;

boost::spirit::x3::symbols<ast::optoken> equality_op;
boost::spirit::x3::symbols<ast::optoken> relational_op;
boost::spirit::x3::symbols<ast::optoken> logical_op;
boost::spirit::x3::symbols<ast::optoken> additive_op;
boost::spirit::x3::symbols<ast::optoken> multiplicative_op;
boost::spirit::x3::symbols<ast::optoken> unary_op;
boost::spirit::x3::symbols<> keywords;

void add_keywords() noexcept {
    static bool once = false;
    if (once) return;
    once = true;

    logical_op.add
        ("&&", ast::optoken::and_)
        ("||", ast::optoken::or_);

    equality_op.add
        ("==", ast::optoken::equal)
        ("!=", ast::optoken::not_equal);

    relational_op.add
        ("<", ast::optoken::less)
        ("<=", ast::optoken::less_equal)
        (">", ast::optoken::greater)
        (">=", ast::optoken::greater_equal);

    additive_op.add
        ("+", ast::optoken::plus)
        ("-", ast::optoken::minus);

    multiplicative_op.add
        ("*", ast::optoken::times)
        ("/", ast::optoken::divide);

    unary_op.add
        ("+", ast::optoken::positive)
        ("-", ast::optoken::negative)
        ("!", ast::optoken::not_);

    keywords.add
        ("if")
        ("else")
        ("while")
        ("return")
        ("int")
        ("void")
        ("bool")
        ("true")
        ("false");
}

}