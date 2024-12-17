#include "expression_def.hpp"
#include "config.hpp"

namespace jincc::parser {

BOOST_SPIRIT_INSTANTIATE(expression_type, iterator_type, context_type);

}