#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  int tmp = -1;
  for (int i : arr) {
    if (i != tmp) {
      answer.push_back(i);
      tmp = i;
    }
  }
  return answer;
}

#include <iostream>
int main() {
  solution(vector<int>{1, 1, 3, 3, 0, 1, 1});
  solution(vector<int>{4, 4, 4, 3, 3});
}