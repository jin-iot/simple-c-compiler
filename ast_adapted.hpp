#pragma once

#include "ast.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::unary,
    operator_, operand_
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::operation,
    operator_, operand_
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::function_call,
    function_name, args
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::expression,
    first, rest
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::assignment,
    lhs, rhs
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::variable_declaration,
    assign
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::if_statement,
    condition, then, else_
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::while_statement,
    condition, body
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::return_statement,
    expr
)

BOOST_FUSION_ADAPT_STRUCT(jincc::ast::function,
    return_type, function_name, args, body
)