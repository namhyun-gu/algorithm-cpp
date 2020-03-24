#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> queue;

    int idx = 0;
    int day = 0;
    while (day < k) {
      if (dates[idx] <= day && idx < dates.size()) {
        queue.push(supplies[idx]);
        idx++;
      }

      if (stock == 0) {
        stock += queue.top();
        queue.pop();
        answer++;
      }
      stock--;
      day++;
    }
    return answer;
}

#include <iostream>
#include <assert.h>
main() {
  assert(solution(4, vector<int>{4, 10, 15}, vector<int>{20, 5, 10}, 30) == 2);
  assert(solution(4, vector<int>{1, 2, 3, 4}, vector<int>{10, 40, 30, 20}, 100) == 4);
}