#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    freopen("input1.txt", "r", stdin);
    // freopen("test.txt", "r", stdin);
    string s;

    std::priority_queue<int> q; // Max priority queue

    while (getline(cin, s)) {
        int curr_elf_calories = std::stoi(s);
        while (getline(cin, s) && s != "") {
            curr_elf_calories+=std::stoi(s);
        }

        q.push(curr_elf_calories);
    }
    int max1 = q.top(); q.pop();
    int max2 = q.top(); q.pop();
    int max3 = q.top(); q.pop();
    cout << max1 + max2 + max3 << endl;

}
