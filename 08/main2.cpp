#include <bits/stdc++.h>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

// Returns score
int dfs_dir(const vector<vector<int>> &grid, int i, int j, int elem, int direction) {
    if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[i].size() - 1) {
        return 0;
    }

    if (grid[i][j] >= elem) {
        return 1;
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

    return 1+dfs_dir(grid, i_new, j_new, elem, direction);
}

// Return score for the i, jth element
int dfs(const vector<vector<int>>& grid, int i, int j) {
    int up_score =  dfs_dir(grid, i-1, j, grid[i][j], UP);
    int down_score = dfs_dir(grid, i+1, j, grid[i][j], DOWN);
    int left_score = dfs_dir(grid, i, j-1, grid[i][j], LEFT);
    int right_score = dfs_dir(grid, i, j+1, grid[i][j], RIGHT);

    return up_score * down_score * left_score * right_score;
}

void part2() {
    vector<vector<int>> grid;

    string s;
    while (getline(cin, s)) {
        vector<int> row(s.size());

        for (int i = 0; i < s.size(); i++) {
            row[i] = s[i] - '0';
        }

        grid.push_back(row);
    }

    int i = 1, j = 3;
    cout << dfs(grid, i, j) << endl;

    int max_val = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            max_val = max(dfs(grid, i, j), max_val);
            cout << i << " " <<  j << endl;
            cout << dfs(grid, i, j) << endl;
        }
        cout << endl;
    }
    cout << max_val << endl;
}


int main(int argc, char **argv)
{
    string s;
    
    freopen("input.txt", "r", stdin);
    /* freopen("test.txt", "r", stdin); */

    part2();

}
