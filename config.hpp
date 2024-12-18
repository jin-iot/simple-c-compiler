#pragma once

#include "error_handler.hpp"

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3.hpp>

#include <string>
#include <functional>

namespace jincc::parser {

using iterator_type = std::string::const_iterator;
using phrase_context_type =
    boost::spirit::x3::phrase_parse_context<
        boost::spirit::x3::ascii::space_type
    >::type;

using error_handler_type = error_handler<iterator_type>;
using context_type = boost::spirit::x3::context<
    error_handler_tag,
    std::reference_wrapper<error_handler_type>,
    phrase_context_type
>;

}