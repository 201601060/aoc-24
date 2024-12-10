#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void moveBlock(int i, vector<int>& blocks_index, vector<int>& block_size, map<int, int>& spaces) {
    bool isMovable = false;
    int oldIndex = -1;
    int oldSize = 1000;

    for (auto& [i_s, s_s] : spaces) {
        if (i_s < blocks_index[i]) {
            if (s_s >= block_size[i]) {
                blocks_index[i] = i_s;
                isMovable = true;
                oldIndex = i_s;
                oldSize = s_s;
                break;
            }
        }
    }

    if (isMovable) {
        spaces[oldIndex + block_size[i]] = oldSize - block_size[i];
        spaces[oldIndex] = -1;
    }
}

void solve2() {
    ifstream file("in");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file\n";
        return;
    }

    string line;
    getline(file, line);

    vector<int> block_size;
    vector<int> blocks_index;
    map<int, int> spaces;

    int index = 0;
    for (size_t i = 0; i < line.size(); ++i) {
        int s = line[i] - '0';
        if (i % 2 == 0) {
            block_size.push_back(s);
            blocks_index.push_back(index);
            index += s;
        } else {
            spaces[index] = s;
            index += s;
        }
    }

    for (int i = block_size.size() - 1; i >= 0; --i) {
        moveBlock(i, blocks_index, block_size, spaces);
    }

    uint64_t sum = 0;
    for (size_t b = 1; b < block_size.size(); ++b) {
        for (int b_i = blocks_index[b]; b_i < blocks_index[b] + block_size[b]; ++b_i) {
            sum += b * b_i;
        }
    }
    cout << sum << endl;
}

int main() {
    solve2();
    return 0;
}

