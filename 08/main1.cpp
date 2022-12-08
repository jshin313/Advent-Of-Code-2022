#include <bits/stdc++.h>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

// Returns if the tree is visible from the direction specified
int dfs_dir(const vector<vector<int>> &grid, int i, int j, int elem, int direction) {
    if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[i].size() - 1) {
        return 1;
    }
    
    if (grid[i][j] >= elem) {
        return 0;
    }

    int i_new = i, j_new = j;
    switch (direction) {
        case UP:
            i_new = i-1;
            break;
        case DOWN:
            i_new = i+1;
            break;
        case LEFT:
            j_new = j-1;
            break;
        case RIGHT:
            j_new = j+1;
            break;
    }

    return dfs_dir(grid, i_new, j_new, elem, direction);
}

// Return if tree is visible from any side
bool dfs(const vector<vector<int>>& grid, int i, int j) {
    return dfs_dir(grid, i-1, j, grid[i][j], UP) || 
        dfs_dir(grid, i+1, j, grid[i][j], DOWN) ||
        dfs_dir(grid, i, j-1, grid[i][j], LEFT) || 
        dfs_dir(grid, i, j+1, grid[i][j], RIGHT);
}

void part1() {
    vector<vector<int>> grid;

    string s;
    while (getline(cin, s)) {
        vector<int> row(s.size());

        for (int i = 0; i < s.size(); i++) {
            row[i] = s[i] - '0';
        }

        grid.push_back(row);
    }

    int sum = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            sum += dfs(grid, i, j);
            /* cout << grid[i][j] << ":" << dfs(grid, i, j) << " "; */
        }
        cout << endl;
    }
    cout << sum << endl;
}

void part2() {

}

int main(int argc, char **argv)
{
    string s;
    
    freopen("input.txt", "r", stdin);
    /* freopen("test.txt", "r", stdin); */

    part1();

}
