#include <bits/stdc++.h>

using namespace std;

int find_value(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 27;
    }
}

int main(int argc, char **argv)
{
    freopen("input1.txt", "r", stdin);
    // freopen("test.txt", "r", stdin);
    string s1;

    int sum = 0;
    while (cin >> s1) {
        string s2; string s3;
        cin >> s2; cin >> s3;

        std::bitset<128> bitset1;
        std::bitset<128> bitset2;
        std::bitset<128> bitset3;

        for (int i = 0; i < s1.size(); i++) {
            bitset1.set(s1[i]);
        }
        for (int i = 0; i < s2.size(); i++) {
            bitset2.set(s2[i]);
        }
        for (int i = 0; i < s3.size(); i++) {
            bitset3.set(s3[i]);
        }

        std::bitset<128> result = bitset1 & bitset2 & bitset3;
        // cout << result.to_string() << endl;

        char target;
        for (int i = 0; i < 128; i++) {
            if (result.test(i) == 1) {
                target = (char)i;
                break;
            }
        }

        sum += find_value(target);

    }
    cout << sum << endl;

}
