#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;
  bool in_skill[26] = {0};
  vector<char> skill_queue;

  for (string skill_tree : skill_trees) {
    for (char c : skill) {
      in_skill[c - 'A'] = true;
      skill_queue.insert(skill_queue.begin(), c);
    }

    bool valid = true;
    for (char c : skill_tree) {
      if (!in_skill[c - 'A'])
        continue;

      if (c == skill_queue.back()) {
        skill_queue.pop_back();
      } else {
        valid = false;
      }
    }

    if (valid)
      answer++;
    skill_queue.clear();
  }
  return answer;
}

#include <iostream>
main() {
  cout << solution("CBD", vector<string>{"BACDE", "CBADF", "AECB", "BDA"})
       << endl; // 2
}
