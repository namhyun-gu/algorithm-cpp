#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool is_prime(int n) {
  if (n == 0 || n == 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    sort(numbers.begin(), numbers.end());
    do {
      for (int i = 0; i < numbers.size(); i++) {
        string subs = numbers.substr(0, i);
        v.push_back(atoi((subs.empty() ? numbers : subs).c_str()));
      }
    } while (next_permutation(numbers.begin(), numbers.end()));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &i : v) {
      if (is_prime(i)) {
        answer++;
      }
    }
    return answer;
}

#include <iostream>
main() {
  cout << solution("17") << endl;
  cout << solution("1234") << endl;
  cout << solution("011") << endl;
  cout << solution("000") << endl;
  cout << solution("0000") << endl;
  cout << solution("0000000") << endl;
  cout << solution("013") << endl;
}