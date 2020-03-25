#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;
  sort(citations.begin(), citations.end(), greater<int>());
  for (int h = citations[0]; h > 0; h--) {
    int cnt = 0;
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] >= h)
        cnt++;
      else
        break;
    }
    if (cnt >= h) {
      answer = h;
      break;
    }
  }
  return answer;
}

#include <assert.h>

#include <iostream>
main() {
  assert(solution({3, 0, 6, 1, 5}) == 3);
  assert(solution({2, 2, 2, 2}) == 2);
}