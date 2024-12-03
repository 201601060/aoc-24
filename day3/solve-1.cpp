// regex deez nuts

#include <cctype>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

int main() {
    std::ifstream inp("day3.input");
    char ch;
    int a, b = 0;
    int32_t sum = 0;
    bool comma = false;
    std::vector<char> pattern;

    while(inp.get(ch)) {
        switch(ch) {
            case 'm': {
                if(pattern.empty()) pattern.push_back(ch);
                else {
                    a = 0;
                    b = 0;
                    comma = false;
                    pattern.clear();
                }
            }
            case 'u': {
                if(pattern.back() == 'm') pattern.push_back(ch);
                else {
                    a = 0;
                    b = 0;
                    comma = false;
                    pattern.clear();
                }
                break;
            }

            case 'l': {
                if(pattern.back() == 'u') pattern.push_back(ch);
                else {
                    a = 0;
                    b = 0;
                    comma = false;
                    pattern.clear();
                }
                break;
            }
            case '(': {
                if(pattern.back() == 'l') pattern.push_back(ch);
                else {
                    a = 0;
                    b = 0;
                    comma = false;
                    pattern.clear();
                }
                break;
            }
            case ',': {
                if(!comma && isdigit(pattern.back())) {
                    comma = true;
                    pattern.push_back(ch);
                }
                else {
                    a = 0;
                    b = 0;
                    comma = false;
                    pattern.clear();
                }
                break;
            }
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6': case '7':
            case '8': case '9': {
                if(comma) {
                    b = b*10 + (ch-'0');
                    pattern.push_back(ch);
                }
                else {
                    if(pattern.back() == '(' || isdigit(pattern.back())){
                        a = a*10 + (ch-'0');
                        pattern.push_back(ch);
                    }
                    else pattern.clear();
                }
                break;
            }
            case ')': {
                if(comma && isdigit(pattern.back())) {
                    sum += a*b;
                }
                a = 0;
                b = 0;
                comma = false;
                pattern.clear();
                break;
            }
            default:
                a = 0;
                b = 0;
                comma = false;
                pattern.clear();
                break;
        }
    }
    std::cout<<sum<<std::endl;
    return 0;
}

