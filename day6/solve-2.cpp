#include <iostream>
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
    std::pair<int, int> start_pos{-1, -1};
    std::pair<int, int> pos{-1, -1};
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '^') {
                start_pos = {i, j};
                grid[i][j] = '.';
            }
        }
    }

    auto isCyclePresent = [&]() {
        int dir = 0;
        pos = start_pos;
        std::vector<bool> visited(R * C * 4);
        while(true) {
            int vis_pos = (C * pos.first + pos.second) * 4 + dir;
            if(visited[vis_pos]) return true;
            visited[vis_pos] = true;
            int next_r = pos.first + dirs[dir].first;
            int next_c = pos.second + dirs[dir].second;
            if(!(0 <= next_r && next_r < R && 0 <= next_c && next_c < C)) return false;
            if(grid[next_r][next_c] == '.') pos = {next_r, next_c};
            else dir = (dir + 1) % 4;
        }
    };

    int ans = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '.' && start_pos != std::make_pair(i, j)) {
                grid[i][j] = '#';
                if(isCyclePresent()) {
                    ans++;
                }
                grid[i][j] = '.';
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
