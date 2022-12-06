#include <bits/stdc++.h>

using namespace std;

int get_start(string s)
{
    int PART_1_SIZE = 4;
    int PART_2_SIZE = 14;
    vector<char> chunk(PART_2_SIZE);

    for (unsigned int i = 0; i < s.size() - chunk.size() + 1; i++) {
        for (int j =0 ; j < chunk.size() ; j++) {
            chunk[j] = s[i+j];
        }

        int total = 0;
        unordered_map<char, int> hmap;
        for (int j = 0; j < chunk.size(); j++)
        {
            if (hmap.find(chunk[j]) != hmap.end()) {
                break;
            } else {
                hmap[chunk[j]] = 1;
                /* cout << chunk[j] << " "; */
                total++;
            }
        }

        if (total == chunk.size()) {
            return i+chunk.size();
        }
    }

    return 0;

}
int main(int argc, char **argv)
{
    string s;
    
    freopen("input.txt", "r", stdin);
    /* freopen("test.txt", "r", stdin); */

    getline(cin, s);
    /* cout << s << endl; */
    cout << get_start(s) << endl;

}
