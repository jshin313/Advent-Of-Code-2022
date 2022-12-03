#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    freopen("input1.txt", "r", stdin);
    // freopen("test.txt", "r", stdin);
    string s;

    int max_calories = 0;
    while (getline(cin, s)) {
        int curr_elf_calories = std::stoi(s);
        while (getline(cin, s) && s != "") {
            curr_elf_calories+=std::stoi(s);
        }

        max_calories = max(max_calories, curr_elf_calories);
    }
    cout << max_calories << endl;

}
