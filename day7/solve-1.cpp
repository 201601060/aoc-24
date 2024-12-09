#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool validCombination(int64_t valTillNow, int i, int64_t& testVal, std::vector<int>& nums, int& N) {
    if(i == N-1) {
        return (valTillNow + nums[i] == testVal || valTillNow * nums[i] == testVal);
    }
    return (validCombination(valTillNow + nums[i], i+1, testVal, nums, N) ||
            validCombination(valTillNow * nums[i], i+1, testVal, nums, N));
};

int main() {
    int64_t ans = 0;
    int64_t testVal;
    std::string line;
    std::ifstream in("in");
    while(std::getline(in, line)) {
        std::istringstream ss(line);
        ss >> testVal;
        int n;
        ss.ignore(1, ':');
        std::vector<int> nums;
        while(ss >> n) {
            nums.push_back(n);
        }

        int N = nums.size();
        if(validCombination(nums[0], 1, testVal, nums, N)) {
            ans += testVal;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
