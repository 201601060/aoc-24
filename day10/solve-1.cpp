#include <iostream>
#include <set>
#include <stack>
#include <utility>

using namespace std;

vector<string> grid;

int findScore(int x, int y, int& R, int& C) {
    int i, j, ans = 0;
    stack<pair<int, int>> S;
    set<pair<int, int>> vis;
    S.push({x, y});
    while(S.size()) {
        auto pos = S.top();
        S.pop();
        i = pos.first;
        j = pos.second;

        if(vis.find({i, j}) != vis.end()) continue;

        vis.insert({i, j});
        if(grid[i][j] == '9') {
            ans++;
            continue;
        }

        if(i+1 < R && grid[i+1][j] == char(grid[i][j] + 1)) S.push({i+1, j});
        if(i-1 >= 0 && grid[i-1][j] == char(grid[i][j] + 1)) S.push({i-1, j});
        if(j+1 < C && grid[i][j+1] == char(grid[i][j] + 1)) S.push({i, j+1});
        if(j-1 >= 0 && grid[i][j-1] == char(grid[i][j] + 1)) S.push({i, j-1});
    }
    return ans;
}

int main() {
    string line;

    while(cin>>line) {
        grid.push_back(line);
    }

    int R = grid.size(), C = grid[0].size();

    int ans = 0, x, y;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C ; j++) {
            if(grid[i][j] == '0') {
                ans += findScore(i, j, R, C);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}

