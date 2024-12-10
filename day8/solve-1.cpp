#include <iostream>
#include <string>
#include <vector>

int main() {
    int R = 50;
    std::string line;
    std::vector<std::string> grid(R);
    for(int i = 0; i < R; i++) {
        std::cin >> grid[i];
    }
    int C = grid[0].size();

    auto isAntinode = [&](int r, int c) {
        int r_start = floor(r/2.0), r_end = ceil((R + r)/2.0),
            c_start = floor(c/2.0), c_end = ceil((C + c)/2.0);
        for(int i = r_start; i < r_end; i++) {
            for(int j = c_start; j < c_end; j++) {
                if(i != r && j!= c) {
                    if(grid[i][j] != '.') {
                        int i1 = 2*i-r, j1 = 2*j-c;
                        if(0 <= i1 && i1 < R && 0 <= j1 && j < R) {
                            if(grid[i][j] == grid[i1][j1]) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    };

//  std::unordered_map<char, std::vector<std::pair<int, int>>> ants;
//  for(int i = 0; i < R; i++) {
//      for(int j = 0; j < C; j++) {
//          if(grid[i][j] != '.') ants[grid[i][j]].push_back({i, j});
//      }
//  }
//  auto isAntinode = [&](int r, int c) {
//      for(auto& ch: ants) {
//          for(auto& pos: ch.second) {
//              if(r != pos.first || c != pos.second) {
//                  int i = pos.first, j = pos.second,
//                  i1 = 2*i-r, j1 = 2*j-c;
//                  if(0 <= i1 && i1 < R && 0 <= j1 && j < R) {
//                      if(ch.first == grid[i1][j1]) {
//                          return true;
//                      }
//                  }
//              }
//          }
//      }
//      return false;
//  };

    int ans = 0;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(isAntinode(r, c)) ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
