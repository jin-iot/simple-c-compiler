#pragma once

#include <boost/spirit/home/x3.hpp>

namespace jincc::parser {

using boost::spirit::x3::raw;
using boost::spirit::x3::lexeme;
using boost::spirit::x3::alpha;
using boost::spirit::x3::alnum;

struct identifier_class;
using identifier_type =
    boost::spirit::x3::rule<identifier_class, std::string>;
identifier_type const identifier = "identifier";
auto const identifier_def = raw[lexeme[(alpha | '_') >> *(alnum | '_')]];

BOOST_SPIRIT_DEFINE(identifier);

}