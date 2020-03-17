#include <string>
#include <vector>

using namespace std;

vector<vector<int>> user_pattern = {
    {1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  vector<int> correct_cnt = {0, 0, 0};
  for (int index = 0; index < answers.size(); index++) {
    for (int user = 0; user < 3; user++) {
      int userAnswer = user_pattern[user][index % user_pattern[user].size()];
      if (answers[index] == userAnswer) {
        correct_cnt[user]++;
      }
    }
  }
  int max_cnt = 0;
  for (int user = 0; user < 3; user++) {
    if (correct_cnt[user] > max_cnt) {
      max_cnt = correct_cnt[user];
    }
  }
  for (int user = 0; user < 3; user++) {
    if (correct_cnt[user] == max_cnt) {
      answer.push_back(user + 1);
    }
  }
  return answer;
}

int main() {
  solution(vector<int>{1, 2, 3, 4, 5});
  solution(vector<int>{1, 3, 2, 4, 2});
}