// regexing... ofc better code exists out there
// first time actually doing regex stuff in c++

#include <cctype>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <ostream>
#include <regex>
#include <string>

int main() {
    std::ifstream inp("day3.input");
    std::string input_string;
    std::regex const do_pattern(R"(do(?!n't))");
    std::regex const mul_pattern(R"(mul\(\d+,\d+\))");
    std::regex const combined_pattern(R"(don't|mul\(\d+,\d+\))");
    std::regex const num_pattern(R"(\d+)");
    int prod = 1;
    int32_t sum = 0;
    while(std::getline(inp, input_string, '\0')) {
        for (std::smatch combined_match; regex_search(input_string, combined_match, combined_pattern);) {
            std::string combined_match_str = combined_match.str();
            if(std::regex_match(combined_match_str, mul_pattern)) {
                auto n_begin = std::sregex_iterator(combined_match_str.begin(), combined_match_str.end(), num_pattern);
                auto n_end = std::sregex_iterator();
                for (std::sregex_iterator i = n_begin; i != n_end; ++i) {
                    std::smatch match = *i;
                    std::string match_str = match.str();
                    prod *= std::stoi(match_str);
                }
                sum += prod;
                prod = 1;
                input_string = combined_match.suffix();
            } else {
                input_string = combined_match.suffix();
                if (!regex_search(input_string, do_pattern)) break;
                for (std::smatch do_match; regex_search(input_string, do_match, do_pattern);) {
                    std::string do_match_str = do_match.str();
                    input_string = do_match.suffix();
                    break;
                }
            }
        }
    }
    std::cout << sum << '\n';
    return 0;
}
