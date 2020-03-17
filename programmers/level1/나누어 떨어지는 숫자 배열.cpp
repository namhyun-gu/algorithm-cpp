#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
  vector<int> answer;
  for (int i : arr) {
    if (i % divisor == 0)
      answer.push_back(i);
  }
  sort(answer.begin(), answer.end());
  if (answer.empty())
    answer.push_back(-1);
  return answer;
}

int main() {
  solution(vector<int>{5, 9, 7, 10}, 5);
  solution(vector<int>{2, 36, 1, 3}, 1);
  solution(vector<int>{3, 2, 6}, 10);
}