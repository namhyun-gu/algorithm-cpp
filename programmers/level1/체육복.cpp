#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;
  int cnt[31] = {0};
  for (int i = 1; i <= n; i++) cnt[i] = 1;
  for (int i : reserve) cnt[i]++;
  for (int i : lost) cnt[i]--;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      if (cnt[i - 1] > 1) {
        cnt[i - 1]--;
        cnt[i]++;
      } else if (cnt[i + 1] > 1) {
        cnt[i + 1]--;
        cnt[i]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 0) {
      answer++;
    }
  }
  return answer;
}

#include <iostream>

int main() {
  cout << solution(5, vector<int>{2, 4}, vector<int>{1, 3, 5}) << endl;  // 5
  cout << solution(5, vector<int>{2, 4}, vector<int>{3}) << endl;        // 4
  cout << solution(3, vector<int>{3}, vector<int>{1}) << endl;           // 2
  cout << solution(2, vector<int>{2}, vector<int>{2}) << endl;           // 2
  cout << solution(30, vector<int>{1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                                   21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
                   vector<int>{})
       << endl;
  return 0;
}