#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_strs;
    for (int i = 0; i < numbers.size(); i++) {
      num_strs.push_back(to_string(numbers[i]));
    }
    sort(num_strs.begin(), num_strs.end(), [](string a, string b) {
      return a + b > b + a;
    });
    if (num_strs[0] == "0") return "0";
    for (int i = 0; i < num_strs.size(); i++) {
      answer += num_strs[i];
    }
    return answer;
}

#include <iostream>
#include <assert.h>
main() {
  assert(solution({6, 10, 2}) == "6210");
  assert(solution({0, 0, 0, 0}) == "0");
  assert(solution({3, 30, 34, 5, 9}) == "9534330");
  assert(solution({40, 403}) == "40403");
  assert(solution({40, 405}) == "40540");
  assert(solution({40, 404}) == "40440");
  assert(solution({12, 121}) == "12121");
  assert(solution({21, 212}) == "21221");
  assert(solution({70, 0, 0, 0}) == "70000");
  assert(solution({0, 0, 0, 1000}) == "1000000");
  assert(solution({12, 1213}) == "121312");
}