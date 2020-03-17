#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  bool *primes = new bool[n + 1];
  fill_n(primes, n + 1, true);

  for (int i = 2; i * i <= n; i++)
    if (primes[i])
      for (int j = i * i; j <= n; j += i)
        primes[j] = false;

  for (int i = 2; i <= n; i++)
    if (primes[i])
      answer++;
  return answer;
}

#include <iostream>
main() {
  cout << solution(10) << endl;
  cout << solution(5) << endl;
}