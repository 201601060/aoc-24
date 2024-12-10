#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {
    int R = 50;
    std::string line;
    std::vector<std::string> grid(R);
    for(int i = 0; i < R; i++) {
        std::cin >> grid[i];
    }
    int C = grid[0].size();

    std::unordered_map<char, std::vector<std::pair<int, int>>> ants;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] != '.') ants[grid[i][j]].push_back({i, j});
        }
    }

    std::vector<std::vector<bool>> antinodes(R, std::vector<bool>(C, false));

    for(auto& ch: ants) {
        std::vector<std::pair<int, int>> ch_pos = ch.second;
        if(ch_pos.size() > 1) {
            for(int p1 = 0; p1 < ch_pos.size(); p1++) {
                for(int p2 = p1+1; p2 < ch_pos.size(); p2++) {
                    if(p1 == p2) continue;
                    else {
                        int r_diff = ch_pos[p2].first - ch_pos[p1].first,
                        c_diff = ch_pos[p2].second - ch_pos[p1].second;
                        int x1 = ch_pos[p1].first - r_diff, y1 = ch_pos[p1].second - c_diff,
                        x2 = ch_pos[p2].first + r_diff, y2 = ch_pos[p2].second + c_diff;

                        antinodes[ch_pos[p1].first][ch_pos[p1].second] = true;
                        antinodes[ch_pos[p2].first][ch_pos[p2].second] = true;
                        while(0 <= x1 && x1 < R && 0 <= y1 && y1 < C) {
                            antinodes[x1][y1] = true;
                            x1 -= r_diff;
                            y1 -= c_diff;
                        }
                        while(0 <= x2 && x2 < R && 0 <= y2 && y2 < C) {
                            antinodes[x2][y2] = true;
                            x2 += r_diff;
                            y2 += c_diff;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(antinodes[i][j]) ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
