#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int dp[100001] = {0};

  cin >> N;

  dp[1] = 1;
  dp[2] = 2;
  for (int n = 3; n <= N; n++) {
    dp[n] = n;
    for (int i = 2; i * i <= n; i++) {
      dp[n] = min(dp[n], dp[n - i * i] + 1);
    }
  }
  cout << dp[N] << endl;
}