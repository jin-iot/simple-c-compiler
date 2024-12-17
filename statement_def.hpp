#pragma once

#include "ast.hpp"
#include "ast_adapted.hpp"
#include "statement.hpp"
#include "expression.hpp"
#include "common.hpp"
#include "error_handler.hpp"

#include <boost/spirit/home/x3.hpp>

namespace jincc {
namespace parser {

using boost::spirit::x3::raw;
using boost::spirit::x3::lexeme;
using namespace boost::spirit::x3::ascii;

struct statement_list_class;
struct variable_declaration_class;
struct assignment_class;

}
}