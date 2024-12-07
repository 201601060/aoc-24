#include <iostream>
#include <set>
#include <utility>
#include <vector>
int main() {
    int R = 130;
    std::vector<std::string> grid(R);
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for(int i = 0; i < R; i++) {
        std::cin >> grid[i];
    }
    int C = grid[0].size();
    std::pair<int, int> pos{-1, -1};
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '^') {
                pos = {i, j};
                grid[i][j] = '.';
            }
        }
    }
    int dir = 0;
    std::set<std::pair<int, int>> visited;
    while(true) {
        visited.insert({pos.first, pos.second});
        int next_r = pos.first + dirs[dir].first;
        int next_c = pos.second + dirs[dir].second;

        if(!(0 <= next_r && next_r < R && 0 <= next_c && next_c < C)) break;
        if(grid[next_r][next_c] == '.') pos = {next_r, next_c};
        else dir = (dir + 1) % 4;
    }
    std::cout << visited.size() << '\n';
    return 0;
}
