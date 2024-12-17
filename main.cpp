#include "vm.hpp"

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
namespace popt = boost::program_options;

#include <string>
#include <print>
#include <sstream>

int main(int argc, char** argv) {
    int ret = 0;
    popt::variables_map var_map;
    jincc::vm::machine machine;
    popt::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("file,f", popt::value<std::string>(), "input file")
    ;
    popt::store(popt::parse_command_line(argc, argv, desc), var_map);
    popt::notify(var_map);

    std::println("*** C compiler! ***");

    if (var_map.count("help") || argc == 1) {
        std::stringstream ss;
        std::string desc_;
        ss << desc;
        desc_ = ss.str();
        std::println("{}", desc_);
        return 1;
    }

    return ret;
};