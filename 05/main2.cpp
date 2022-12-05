#include <bits/stdc++.h>

using namespace std;

void print_stacks(vector<vector<char>> stacks) {
    for (int i = 0; i < stacks.size(); i++){
        for (int j = 0; j < stacks[i].size(); j++) {
            cout << stacks[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    freopen("input.txt", "r", stdin);
    int stack_num = 9;
    int stack_height = 8;

    /* freopen("test.txt", "r", stdin); */
    /* int stack_num = 3; */
    /* int stack_height = 3; */
    string s;

    int sum = 0;

    std::vector<std::vector<char>> stacks(stack_num,
            std::vector<char>(0));

    for (int j = 0; j < stack_height; j++) {
        getline(cin, s);
         /* cout << s << endl; */
        for (int i = 1; i < s.size(); i+=4) {
            int stack_idx = (i-1)/4;
            if (s[i] != ' ') {
                /* cout << s[i] << endl; */
                stacks[stack_idx].push_back(s[i]);
            }

        }
    }

    print_stacks(stacks);
    for (int i = 0; i < stacks.size(); i++) {
        std::reverse(stacks[i].begin(), stacks[i].end());
    }
    print_stacks(stacks);

    getline(cin, s);
    getline(cin, s);

    while (cin >> s) {
        int num_moves, initial_stack, end_stack;
        cin >> num_moves;
        cin >> s;
        cin >> initial_stack;
        cin >> s;
        cin >> end_stack;

        /* cout << num_moves << endl; */

        // 0 indexing
        initial_stack--; end_stack--;

        vector<char> temp;
        for (int i =0; i < num_moves; i++) {
            print_stacks(stacks);

            vector<char> start_stck = stacks[initial_stack];
            char crate = start_stck[start_stck.size() - 1];
            stacks[initial_stack].pop_back();

            temp.push_back(crate);

        }

        for (int i = num_moves - 1; i >= 0; i--) {

            stacks[end_stack].push_back(temp[i]);
        }
    }
    /* print_stacks(stacks); */

    for (auto stck: stacks) {
        cout << stck[stck.size() - 1] << "";
    }
    cout << endl;

}
