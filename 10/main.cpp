#include <bits/stdc++.h>

using namespace std;

void part1() {
    int cycle = 1;
    int X = 1;
    vector<int> signal_strength;

    // Use 1 based indexing, so place dummy value
    signal_strength.push_back(cycle * X);
    string instruction;
    while (cin >> instruction) {

        if (instruction == "noop") {
            signal_strength.push_back(cycle * X);
            cycle++;
        } else {
            int val;
            cin >> val;
            signal_strength.push_back(cycle * X);
            cycle++;
            signal_strength.push_back(cycle * X);
            cycle++;
            X+=val;
        }
    }

    int sum = 0;
    for (int i = 0; i < signal_strength.size(); i++) {
        if (i == 20 || i == 60 || 100 == i || i == 140 || i == 180 || i == 220)  {
            sum += signal_strength[i];
        }
    }
    cout << sum << endl;
}

// X determines middle idx of sprite
void draw_pixel(int cycle, int X) {
    if (abs((cycle%40) -1 - X) < 2) {
        cout << '#';
    } else {
        cout << '.';
    }

    if (cycle % 40 == 0) {
        cout << endl;
    }
}

void part2() {
    int cycle = 1;
    int X = 1;

    string instruction;
    while (cin >> instruction) {

        if (instruction == "noop") {
            draw_pixel(cycle, X);
            cycle++;
        } else {
            int val;
            cin >> val;
            draw_pixel(cycle, X);
            cycle++;
            draw_pixel(cycle, X);
            cycle++;
            X+=val;
        }
    }

}

int main(int argc, char **argv)
{
    string s;

    
    freopen("input.txt", "r", stdin);
    /* freopen("test.txt", "r", stdin); */

    /* part1(); */
    part2();
}
