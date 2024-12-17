#pragma once

#include <vector>
#include <cstdint>

namespace jincc::vm {

enum class byte_code : int {
    neg,
    add,
    sub,
    mul,
    div,

    not_,
    eq,
    neq,
    lt,
    lte,
    gt,
    gte,

    and_,
    or_,

    load,
    store,

    int_,
    true_,
    false_,

    jmp,
    jmp_if,

    stk_adj,
    call,
    ret,
};

class machine {
public:
    machine(unsigned stack_size = 4096) : stack_(stack_size) {}

    int execute(std::vector<int> const& code) {
        return execute(code, code.begin(), this->stack_.begin());
    }

private:
    int execute(std::vector<int> const& code,
                std::vector<int>::const_iterator pc,
                std::vector<int>::iterator frame_ptr);

    std::vector<int> stack_;
};

}