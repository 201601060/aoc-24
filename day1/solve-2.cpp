#include <fstream>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  std::vector<int> list1;
  std::unordered_map<int, int> list2_count;
  int n1, n2;
  uint64_t ans = 0;
  while (input >> n1 >> n2) {
    list1.push_back(n1);
    list2_count[n2]++;
  }

  for (const auto &t : list1) {
    ans += t * list2_count[t];
  }
    std::cout << ans << std::endl;
  return 0;
}
