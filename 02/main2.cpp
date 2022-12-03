#include <bits/stdc++.h>

using namespace std;

enum Shape {ROCK=1, PAPER=2, SCISSOR=3};
enum Outcome {LOSE=0, DRAW = 3, WON=6};

std::map<char, Shape> shape_dict = {
    { 'A', ROCK },
    { 'B', PAPER },
    { 'C', SCISSOR },
};

std::map<char, Outcome> outcome_dict = {
    { 'X', LOSE },
    { 'Y', DRAW },
    { 'Z', WON },
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
        Shape opponent = shape_dict[s[0]];
        Outcome outcome = outcome_dict[s[2]];
        Shape you;

        switch (opponent) {
            case ROCK:
                you = (outcome == WON) ? PAPER : SCISSOR;
                break;
            case PAPER:
                you = (outcome == WON) ? SCISSOR : ROCK;
                break;
            case SCISSOR:
                you = (outcome == WON) ? ROCK : PAPER;
                break;
        }

        if (outcome == DRAW) {
            you = opponent;
        }        

        score+=outcome;
        score+=you;
    }
    cout << score << endl;

}
