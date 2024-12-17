#pragma once

#include "expression.hpp"
#include "statement.hpp"

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

#include <string>

namespace jincc::parser {

template <typename Iter>
using error_handler = 
    boost::spirit::x3::error_handler<Iter>;

using error_handler_tag = 
    boost::spirit::x3::error_handler_tag;

struct error_handler_base {
    template <class Iter, class Exception, class Context>
    boost::spirit::x3::error_handler_result on_error(
        Iter& first, Iter const& last,
        Exception const& x, Context const& context)
    {
        using namespace std::string_literals;

        auto msg = "Error! Expecting "s + x.which() + " here:";
        auto error_handler = boost::spirit::x3::get<error_handler_tag>(context).get();
        error_handler(x.where(), msg);
        return boost::spirit::x3::error_handler_result::fail;
    }

};

}