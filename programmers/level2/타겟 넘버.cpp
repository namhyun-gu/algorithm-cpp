#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void search(vector<int> numbers, int index, bool negative, int sum,
            int target) {
  if (index == numbers.size()) return;

  sum += negative ? -numbers[index] : numbers[index];

  search(numbers, index + 1, 0, sum, target);
  search(numbers, index + 1, 1, sum, target);

  if (index == numbers.size() - 1 && sum == target) {
    cnt++;
  }
}

int solution(vector<int> numbers, int target) {
  int answer = 0;
  search(numbers, 0, false, 0, target);
  search(numbers, 0, true, 0, target);
  answer = cnt;
  return answer;
}

#include <iostream>
int main(int argc, char const *argv[]) {
  cout << solution(vector<int>{1, 1, 1, 1, 1}, 3) << endl;
  return 0;
}