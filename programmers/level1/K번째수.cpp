#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  for (vector<int> command : commands) {
    int i = command[0];
    int j = command[1];
    int k = command[2];

    vector<int> tmp = vector<int>(array.begin(), array.end());
    sort(tmp.begin() + i - 1, tmp.begin() + j);
    answer.push_back(tmp[i + k - 2]);
  }
  return answer;
}

int main() {
  solution(vector<int>{1, 5, 2, 6, 3, 7, 4}, vector<vector<int>>{
                                                 vector<int>{2, 5, 3},
                                                 vector<int>{4, 4, 1},
                                                 vector<int>{1, 7, 3},
                                             });
}