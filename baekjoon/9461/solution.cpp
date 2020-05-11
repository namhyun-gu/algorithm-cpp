#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, N;
  long long dp[101];

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;

  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    for (int n = 3; n <= N; n++) {
      dp[n] = dp[n - 3] + dp[n - 2];
    }
    cout << dp[N] << '\n';
  }
}
