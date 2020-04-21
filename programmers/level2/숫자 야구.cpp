#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool is_valid(string candiate, string compare, int strike, int ball) {
  int strikes = 0, balls = 0;
  for (int i = 0; i < 3; i++) {
    if (candiate[i] == compare[i]) {
      strikes++;
    } else if (find(candiate.begin(), candiate.end(), compare[i]) != candiate.end()) {
      balls++;
    }
  }
  return (strikes == strike && balls == ball);
}

int solution(vector<vector<int>> baseball) {
    string s = "123456789";
    set<string> candidates;

    do {
      candidates.insert(s.substr(0, 3));
    } while (next_permutation(s.begin(), s.end()));

    for (auto &round : baseball) {
      string number = to_string(round[0]);
      int strike = round[1];
      int ball = round[2];

      set<string> temp;
      for (auto &candidate : candidates) {
        if (is_valid(candidate, number, strike, ball)) {
          temp.insert(candidate);
        }
      }
      candidates = temp;
    }
    return candidates.size();
}

#include <iostream>
main() {
  solution({
    {123, 1, 1},
    {356, 1, 0},
    {327, 2, 0},
    {489, 0, 1}
  });
}