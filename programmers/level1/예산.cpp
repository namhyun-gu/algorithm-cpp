#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
  int answer = 0;
  sort(d.begin(), d.end());
  for (int cnt = 1; cnt <= d.size(); cnt++) {
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
      sum += d[i];
    }
    if (sum > budget) {
      break;
    }
    answer = cnt;
  }
  return answer;
}

#include <iostream>
main() {
  cout << solution(vector<int>{1, 3, 2, 5, 4}, 9) << endl;  // 3
  cout << solution(vector<int>{2, 2, 3, 3}, 10) << endl;    // 4
}