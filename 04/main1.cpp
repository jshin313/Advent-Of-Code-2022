#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    /* freopen("input1.txt", "r", stdin); */
    freopen("test.txt", "r", stdin);
    string s;

    int sum = 0;
    while (cin >> s) {
        std::string elf1 = s.substr(0, s.find(","));
        std::string elf2 = s.substr(s.find(",")+1);

        int start1 = std::stoi(elf1.substr(0, elf1.find("-")));
        int end1 = std::stoi(elf1.substr(elf1.find("-")+1));

        int start2 = std::stoi(elf2.substr(0, elf2.find("-")));
        int end2 = std::stoi(elf2.substr(elf2.find("-")+1));

        if (start1 <= start2 && end1 >= end2) {
            sum++;
        } else if (start2 <= start1 && end2 >= end1) {
            sum++;
        }
    }
    cout << sum << endl;

}
