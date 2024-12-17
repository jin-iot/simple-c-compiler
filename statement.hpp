#pragma once

#include "ast.hpp"

#include <boost/spirit/home/x3.hpp>

namespace jincc {
namespace parser {

struct statement_class;
using statement_type =
    boost::spirit::x3::rule<statement_class, ast::statement>;
BOOST_SPIRIT_DECLARE(statement_type);

}

parser::statement_type const& statement();

}