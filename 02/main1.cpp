#include <bits/stdc++.h>

using namespace std;

enum Shape {ROCK=1, PAPER=2, SCISSOR=3};
enum Outcome {LOSE=0, DRAW = 3, WON=6};

std::map<char, Shape> dict = {
    { 'A', ROCK },
    { 'B', PAPER },
    { 'C', SCISSOR },
    { 'X', ROCK },
    { 'Y', PAPER },
    { 'Z', SCISSOR },
};

int main(int argc, char **argv)
{
    freopen("input1.txt", "r", stdin);
    // freopen("test.txt", "r", stdin);
    string s;

    int score = 0;
    while (getline(cin, s)) {
        int n = s.size();

        cout << s << endl;
        Shape opponent = dict[s[0]];
        Shape you = dict[s[2]];


        Outcome outcome;

        switch (opponent) {
            case ROCK:
                outcome = (you == PAPER) ? WON : LOSE;
                break;
            case PAPER:
                outcome = (you == SCISSOR) ? WON : LOSE;
                break;
            case SCISSOR:
                outcome = (you == ROCK) ? WON : LOSE;
                break;
        }

        if (opponent == you) {
            outcome = DRAW;
        }        

        score+=outcome;
        score+=you;
    }
    cout << score << endl;

}
