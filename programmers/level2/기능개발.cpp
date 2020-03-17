#include <cmath>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<pair<int, int>> q;

  for (int i = 0; i < progresses.size(); i++) {
    int day = ceil((double)(100 - progresses[i]) / speeds[i]);
    q.push(make_pair(i, day));
  }

  while (!q.empty()) {
    int released = 0;
    pair<int, int> front = q.front();
    while (!q.empty() && q.front().second <= front.second) {
      q.pop();
      released++;
    }
    answer.push_back(released);
  }
  return answer;
}

#include <iostream>
main() {
  for (auto i : solution(vector<int>{93, 30, 55}, vector<int>{1, 30, 5}))
    cout << i << " ";
  cout << endl;

  for (auto i : solution(vector<int>{93, 60, 70}, vector<int>{2, 10, 50}))
    cout << i << " ";
  cout << endl;
}