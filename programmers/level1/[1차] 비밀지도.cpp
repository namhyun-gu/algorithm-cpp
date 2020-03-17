#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;
  for (int i = 0; i < n; i++) {
    string row = "";
    int rowInt = arr1[i] | arr2[i];
    int cmp = 1;
    for (int i = 0; i < n; i++) {
      int cal = rowInt & cmp;
      if (cal == cmp)
        row.insert(0, "#");
      else
        row.insert(0, " ");
      cmp = cmp << 1;
    }
    answer.push_back(row);
  }
  return answer;
}

#include <iostream>
main() {
  for (auto i : solution(5, vector<int>{9, 20, 28, 18, 11},
                         vector<int>{30, 1, 21, 17, 28}))
    cout << i << endl;
  cout << endl;

  for (auto i : solution(6, vector<int>{46, 33, 33, 22, 31, 50},
                         vector<int>{27, 56, 19, 14, 14, 10}))
    cout << i << endl;
  cout << endl;
}