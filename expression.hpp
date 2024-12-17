#pragma once

#include "ast.hpp"
#include "ast_adapted.hpp"

#include <boost/variant.hpp>
#include <boost/spirit/home/x3/nonterminal/rule.hpp>

namespace jincc {
namespace parser {

struct expression_class;
using expression_type =
    boost::spirit::x3::rule<expression_class, ast::expression>;

BOOST_SPIRIT_DECLARE(expression_type);

}

parser::expression_type const& expression();

}