#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    auto cmp = [](int a, int b) {
      return a > b;
    };

    make_heap(scoville.begin(), scoville.end(), cmp);

    int cnt = 0;
    while (scoville.size() > 1) {
      pop_heap(scoville.begin(), scoville.end(), cmp);
      int first = scoville.back();
      scoville.pop_back();

      pop_heap(scoville.begin(), scoville.end(), cmp);
      int second = scoville.back();
      scoville.pop_back();

      scoville.push_back(first + second * 2);
      push_heap(scoville.begin(), scoville.end(), cmp);

      cnt++;

      if (scoville.front() >= K) return cnt;
    }
    return -1;
}

#include <iostream>
#include <assert.h>
main() {
  vector<int> scovile = vector<int>{1, 2, 3, 9, 10 ,12};
  assert(solution(scovile, 7) == 2);
}