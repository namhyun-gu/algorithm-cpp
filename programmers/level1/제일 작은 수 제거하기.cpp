#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  int min = INT8_MAX;
  int minIdx;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < min) {
      min = arr[i];
      minIdx = i;
    }
  }
  arr.erase(arr.begin() + minIdx);
  if (arr.empty())
    answer.push_back(-1);
  else {
    answer.assign(arr.begin(), arr.end());
  }
  return answer;
}

// 문제에 정렬하라는 말이 없었으므로 정렬을 해선 안됨.
#include <iostream>
main() {
  for (auto i : solution(vector<int>{4, 3, 2, 1}))
    cout << i << " ";
  cout << endl;
  for (auto i : solution(vector<int>{4, 4, 3, 3, 2, 2, 1, 1}))
    cout << i << " ";
  cout << endl;
  for (auto i : solution(vector<int>{1, 1, 1, 1, 1}))
    cout << i << " ";
  cout << endl;
  for (auto i : solution(vector<int>{5, 1, 2, 8, 3}))
    cout << i << " ";
  cout << endl;
  for (auto i : solution(vector<int>{10}))
    cout << i << " ";
  cout << endl;
}