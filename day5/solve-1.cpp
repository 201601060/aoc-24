#include <_strings.h>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::ifstream file("day5.inp");
    if(!file.is_open()) {
        std::cerr << "failed to open file";
        return 0;
    }

    std::unordered_map<int, std::set<int>> adj_list;

    std::string line;
    uint16_t ans = 0;

    while(std::getline(file, line)) {
        if(line.empty()) break;
        std::replace(line.begin(), line.end(), '|', ' ');
        std::stringstream ss(line);
        int a, b;
        ss >> a;
        ss >> b;
        adj_list[a].insert(b);
    }

    while(std::getline(file, line)) {
        std::vector<int> check_nums;
        std::replace(line.begin(), line.end(), ',', ' ');
        std::stringstream ss(line);
        int n;
        bool fail = false;
        while(ss >> n) {
            check_nums.push_back(n);
            for(auto& it: check_nums) {
                if(adj_list[n].find(it) != adj_list[n].end()) {
                    fail = true;
                    break;
                }
            }
        }
        if(!fail) {
            int N = check_nums.size();
            ans += check_nums[(N-1)/2];
        }
    }
    std::cout << ans << '\n';
    file.close();
    return 0;
}
