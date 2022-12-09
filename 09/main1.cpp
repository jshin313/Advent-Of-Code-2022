#include <bits/stdc++.h>

using namespace std;

void print_tail_visited(unordered_map<string, int> tail_visited) {
    for (auto iter = tail_visited.cbegin(); iter!= tail_visited.cend(); iter++) {
        cout << iter->first << endl;
    }
}

void print_grid(int head_i, int head_j, int tail_i, int tail_j) {
    int n = 5;
    int m = 5;
    cout << endl;
    for (int i = n-1+head_i; i >= -n + head_i; i--) {
        for (int j = -m+head_j; j < m+head_j; j++) {
            if (head_i == i && head_j == j) {
                cout << "H";
            } else if (tail_i == i && tail_j == j) {
                cout << "T";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void get_tail_position(const int head_i, const int head_j, int &tail_i, int &tail_j) {
    int row_diff = head_i - tail_i;
    int col_diff = head_j - tail_j;


    /* cout << row_diff << " " << col_diff << endl; */

    if (abs(row_diff) == 1 && abs(col_diff) ==1) {
        return;
    }

    if (col_diff == 0) {
        if (row_diff == 2) {
            tail_i++;
        } else if (row_diff == -2) {
            tail_i--;
        }
    }
    else if (row_diff == 0) {
        if (col_diff == 2) {
            tail_j++;
        } else if (col_diff == -2) {
            tail_j--;
        }
    } else {

        if (row_diff > 0 && col_diff > 0) {
            tail_i++;
            tail_j++;
        } else if (row_diff < 0 && col_diff < 0) {
            tail_i--;
            tail_j--;
        } else if (row_diff < 0 && col_diff > 0) {
            tail_i--;
            tail_j++;
        } else if (row_diff > 0 && col_diff < 0) {
            tail_i++;
            tail_j--;
        }
    }

}

void part1() {
    int head_i = 0, head_j = 0;
    int tail_i = 0, tail_j = 0;

    unordered_map<string, int> tail_visited;

    int sum = 0;
    char direction;
    while (cin >> direction) {
        int steps;
        cin >> steps;

        for (int i = 0; i < steps; i++) {
            string coords = std::to_string(tail_i) + "-" + std::to_string(tail_j);
            tail_visited[coords]++;


            switch (direction) {
                case 'R':
                    head_j++;
                    break;
                case 'L':
                    head_j--;
                    break;
                case 'D':
                    head_i--;
                    break;
                case 'U':
                    head_i++;
                    break;
            }

            print_grid(head_i, head_j, tail_i, tail_j);

            get_tail_position(head_i, head_j, tail_i, tail_j);
            print_grid(head_i, head_j, tail_i, tail_j);
        }
    }
    string coords = std::to_string(tail_i) + "-" + std::to_string(tail_j);
    tail_visited[coords]++;

    cout << tail_visited.size() << endl;

    /* print_tail_visited(tail_visited); */

}

int main(int argc, char **argv)
{
    string s;
    
    freopen("input.txt", "r", stdin);
    /* freopen("test2.txt", "r", stdin); */

    part1();

}
