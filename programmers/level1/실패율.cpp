#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  int *cleared = new int[N + 1];
  int *tried = new int[N + 1];
  fill_n(cleared, N + 1, 0);
  fill_n(tried, N + 1, 0);

  for (int i = 0; i < stages.size(); i++) {
    if (stages[i] != N + 1) tried[stages[i]]++;
    for (int j = 1; j < stages[i]; j++) {
      cleared[j]++;
      tried[j]++;
    }
  }

  vector<pair<int, double>> success_rate;
  for (int i = 1; i <= N; i++) {
    success_rate.push_back(
        make_pair(i, tried[i] != 0 ? (double)cleared[i] / tried[i] : 1));
  }

  sort(success_rate.begin(), success_rate.end(),
       [](pair<int, double> a, pair<int, double> b) {
         return a.second == b.second ? a.first < b.first : a.second < b.second;
       });
  for (pair<int, double> p : success_rate) {
    answer.push_back(p.first);
  }

  delete cleared;
  delete tried;
  return answer;
}

#include <iostream>
main() {
  for (auto i : solution(5, vector<int>{2, 1, 2, 6, 2, 4, 3, 3}))
    cout << i << " ";
  cout << std::endl;

  for (auto i : solution(4, vector<int>{4, 4, 4, 4, 4})) cout << i << " ";
  cout << std::endl;
}