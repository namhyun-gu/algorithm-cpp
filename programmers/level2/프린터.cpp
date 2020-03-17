#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  vector<pair<int, int>> print_queue;
  for (int i = 0; i < priorities.size(); i++) {
    print_queue.push_back(make_pair(i, priorities[i]));
  }
  int idx = 1;
  while (!print_queue.empty()) {
    bool is_first = true;
    pair<int, int> front = print_queue.front();
    for (int i = 1; i < print_queue.size(); i++) {
      pair<int, int> print = print_queue[i];
      if (front.second < print.second) {
        is_first = false;
        break;
      }
    }
    print_queue.erase(print_queue.begin());
    if (is_first) {
      if (front.first == location) {
        answer = idx;
        break;
      }
      idx++;
    } else {
      print_queue.push_back(front);
    }
  }
  return answer;
}

#include <iostream>
main() {
  cout << solution(vector<int>{2, 1, 3, 2}, 2) << endl;       // 1
  cout << solution(vector<int>{1, 1, 9, 1, 1, 1}, 0) << endl; // 5
}