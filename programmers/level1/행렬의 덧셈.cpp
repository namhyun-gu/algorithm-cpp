#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  vector<vector<int>> answer;
  for (int i = 0; i < arr1.size(); i++) {
    vector<int> row;
    for (int j = 0; j < arr1[0].size(); j++) {
      row.push_back(arr1[i][j] + arr2[i][j]);
    }
    answer.push_back(row);
  }
  return answer;
}

#include <iostream>
main() {
  solution(vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}},
           vector<vector<int>>{vector<int>{3, 4}, vector<int>{5, 6}});
  solution(vector<vector<int>>{vector<int>{1}, vector<int>{2}},
           vector<vector<int>>{vector<int>{3}, vector<int>{4}});
}