#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, result;
  int dp[31] = {0};

  cin >> N;

  if (N % 2 == 0) {
    dp[0] = 1;
    dp[2] = 3;
    for (int n = 4; n <= N; n += 2) {
      dp[n] = dp[n - 2] * 3;
      for (int i = 4; n - i >= 0; i += 2) {
        dp[n] += dp[n - i] * 2;
      }
    }
    result = dp[N];
  } else {
    result = 0;
  }
  cout << result << endl;
}
