#include "vm.hpp"

namespace jincc::vm {

int machine::execute(std::vector<int> const& code,
                 std::vector<int>::const_iterator pc,
                 std::vector<int>::iterator frame_ptr)
{
    auto stack_ptr = frame_ptr;

    while (true) {
        auto opcode = static_cast<byte_code>(*pc++);
        switch (opcode) {
            case byte_code::neg: {
                stack_ptr[-1] = -stack_ptr[-1];
                break;
            }
            case byte_code::not_: {
                stack_ptr[-1] = !bool(stack_ptr[-1]);
                break;
            }
            case byte_code::add: {
                --stack_ptr;
                stack_ptr[-1] += stack_ptr[0];
                break;
            }
            case byte_code::sub: {
                --stack_ptr;
                stack_ptr[-1] -= stack_ptr[0];
                break;
            }
            case byte_code::mul: {
                --stack_ptr;
                stack_ptr[-1] *= stack_ptr[0];
                break;
            }
            case byte_code::div: {
                --stack_ptr;
                stack_ptr[-1] /= stack_ptr[0];
                break;
            }
            case byte_code::eq: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] == stack_ptr[0];
                break;
            }
            case byte_code::neq: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] != stack_ptr[0];
                break;
            }
            case byte_code::lt: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] < stack_ptr[0];
                break;
            }
            case byte_code::lte: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] <= stack_ptr[0];
                break;
            }
            case byte_code::gt: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] > stack_ptr[0];
                break;
            }
            case byte_code::gte: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] >= stack_ptr[0];
                break;
            }
            case byte_code::and_: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] && stack_ptr[0];
                break;
            }
            case byte_code::or_: {
                --stack_ptr;
                stack_ptr[-1] = stack_ptr[-1] || stack_ptr[0];
                break;
            }
            case byte_code::load: {
                *stack_ptr++ = *pc++;
                break;
            }
            case byte_code::store: {
                --stack_ptr;
                *stack_ptr = stack_ptr[0];
                break;
            }
            case byte_code::int_: {
                *stack_ptr++ = *pc++;
                break;
            }
            case byte_code::true_: {
                *stack_ptr++ = true;
                break;
            }
            case byte_code::false_: {
                *stack_ptr++ = false;
                break;
            }
            case byte_code::jmp: {
                pc += *pc;
                break;
            }
            case byte_code::jmp_if: {
                if (!bool(stack_ptr[-1])) {
                    pc += *pc;
                } else {
                    ++pc;
                }
                --stack_ptr;
                break;
            }
            case byte_code::stk_adj: {
                stack_ptr += *pc++;
                break;
            }
            case byte_code::call: {
                int nargs = *pc++;
                int jump = *pc++;
                int r = execute(code, code.begin() + jump,
                                stack_ptr - nargs);
                stack_ptr[-nargs] = r;
                stack_ptr -= (nargs - 1);
                break;
            }
            case byte_code::ret: {
                return stack_ptr[-1];
            }
        }
    }
}

}