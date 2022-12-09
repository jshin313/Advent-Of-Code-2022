#include <bits/stdc++.h>

using namespace std;

void print_grid(vector<int> &nodes_i, vector<int> &nodes_j, int n, int m) {

    cout << endl;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            char char_to_print = '.';
            for (int idx = nodes_i.size() - 1; idx >= 0; idx--) {
                if (nodes_i[idx] == i && nodes_j[idx] == j) {
                    /* cout << i << " " << j << endl; */
                    char_to_print = idx + '0';
                    if (idx == 0) {
                        char_to_print = 'H';
                    }
                }
            }
            cout << char_to_print;
        }
        cout << endl;
    }
    cout << endl;
}

void get_node_position(vector<int> &nodes_i, vector<int> &nodes_j, int idx) {
    int row_diff = nodes_i[idx-1] - nodes_i[idx];
    int col_diff = nodes_j[idx-1] - nodes_j[idx];

    /* cout << row_diff << " " << col_diff << endl; */

    if (abs(row_diff) == 1 && abs(col_diff) ==1) {
        return;
    }

    if (col_diff == 0) {
        if (row_diff == 2) {
            nodes_i[idx]++;
        } else if (row_diff == -2) {
            nodes_i[idx]--;
        }
    }
    else if (row_diff == 0) {
        if (col_diff == 2) {
            nodes_j[idx]++;
        } else if (col_diff == -2) {
            nodes_j[idx]--;
        }
    } else {

        if (row_diff > 0 && col_diff > 0) {
            nodes_i[idx]++;
            nodes_j[idx]++;
        } else if (row_diff < 0 && col_diff < 0) {
            nodes_i[idx]--;
            nodes_j[idx]--;
        } else if (row_diff < 0 && col_diff > 0) {
            nodes_i[idx]--;
            nodes_j[idx]++;
        } else if (row_diff > 0 && col_diff < 0) {
            nodes_i[idx]++;
            nodes_j[idx]--;
        }
    }

}

void part2() {
    vector<int> nodes_i(10, 0);
    vector<int> nodes_j(10, 0);

    vector<unordered_map<string, int>> coords_visited(10);


    int sum = 0;
    char direction;
    while (cin >> direction) {
        int steps;
        cin >> steps;


        for (int i = 0; i < steps; i++) {
            for (int idx = 0; idx < coords_visited.size(); idx++) {
                int node_i = nodes_i[idx];
                int node_j = nodes_j[idx];
                string coords = std::to_string(node_i) + "-" + std::to_string(node_j);
                coords_visited[idx][coords]++;
            }


            switch (direction) {
                case 'R':
                    nodes_j[0]++;
                    break;
                case 'L':
                    nodes_j[0]--;
                    break;
                case 'D':
                    nodes_i[0]--;
                    break;
                case 'U':
                    nodes_i[0]++;
                    break;
            }

            for (int idx = 0; idx < nodes_i.size() - 1; idx++) {
                get_node_position(nodes_i, nodes_j, idx+1);
            }

            /* print_grid(nodes_i, nodes_j, 5, 5); */
            /* print_grid(nodes_i, nodes_j, 26, 13); */
        }
    }
    for (int idx = 0; idx < coords_visited.size(); idx++) {
        int node_i = nodes_i[idx];
        int node_j = nodes_j[idx];
        string coords = std::to_string(node_i) + "-" + std::to_string(node_j);
        coords_visited[idx][coords]++;
    }

    cout << coords_visited[9].size() << endl;


}

int main(int argc, char **argv)
{
    string s;
    
    freopen("input.txt", "r", stdin);
    /* freopen("test2.txt", "r", stdin); */

    part2();

}
