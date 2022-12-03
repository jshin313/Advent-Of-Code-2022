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
    string s;

    int sum = 0;
    while (cin >> s) {
        int n = s.size();

        unordered_map<char, int> hmap;
        for (int i = 0; i < n/2; i++) {
            hmap[s[i]] = 1;
        }

        for (int i = n/2; i < n; i++) {
            if (hmap.find(s[i]) != hmap.end() && hmap[s[i]] != 0) {
                sum += find_value(s[i]);
                // cout << find_value(s[i]) << endl;
                hmap[s[i]] = 0;

            }        
        }
    }
    cout << sum << endl;

}
