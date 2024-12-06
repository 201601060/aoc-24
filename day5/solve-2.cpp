#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ostream>
#include <queue>
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

    std::unordered_map<int, std::set<int>> after_list;
    std::unordered_map<int, std::set<int>> before_list; // reverse, to later calculate in-degree

    std::string line;
    uint16_t ans = 0;

    while(std::getline(file, line)) {
        if(line.empty()) break;
        std::replace(line.begin(), line.end(), '|', ' ');
        std::stringstream ss(line);
        int a, b;
        ss >> a;
        ss >> b;
        after_list[a].insert(b);
        before_list[b].insert(a);
    }

    while(std::getline(file, line)) {
        std::vector<int> input_nums;
        std::set<int> set_nums;
        std::replace(line.begin(), line.end(), ',', ' ');
        std::stringstream ss(line);
        int n;
        bool fail = false;
        while(ss >> n) {
            input_nums.push_back(n);
            set_nums.insert(n);
        }
        for(int i = 0; i < input_nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(after_list[input_nums[i]].find(input_nums[j]) != after_list[input_nums[i]].end()) {
                    fail = true;
                    break;
                }
            }
        }

        // just now learnt kahn's algo for topological sort, the idea is this
        // - for each vertex save the adj list
        // - for each vertex save its in-degree, i.e., the no. of incoming edges
        //
        // start sort:
        // - vertex with 0 in-degree gets added in a queue
        // - pop the front and add it to the sorted list/result
        // - for each element in queue iterate over its adj list, reduce the in-degree for each list element
        // and add to the queue if 0, then loop again

        if(fail) {
            std::vector<int> inorder_pages;
            std::unordered_map<int, int> in_degree;
            std::queue<int> q;

            for(auto& n: set_nums) {
                for(auto& v: before_list[n]) in_degree[n] += set_nums.count(v);
                if(in_degree[n] == 0) q.push(n);
            }

            int index = 0;
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                inorder_pages.push_back(v);

                for(auto& it: after_list[v]) {
                    if(in_degree.find(it) != in_degree.end()) {
                        in_degree[it]--;
                        if(in_degree[it] == 0) q.push(it);
                    }
                }
            }
            ans += inorder_pages[(inorder_pages.size()-1)/2];
        }
    }
    std::cout << ans << '\n';
    file.close();
    return 0;
}
