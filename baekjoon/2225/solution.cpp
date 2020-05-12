#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  long long dp[201][201] = {{0}};

  cin >> N >> K;

  for (int i = 1; i <= K; i++) {
    dp[0][i] = 1;
  }

  for (int n = 1; n <= N; n++) {
    for (int i = 1; i <= K; i++) {
      for (int k = 1; k <= i; k++) {
        dp[n][i] += dp[n - 1][k];
        dp[n][i] %= 1000000000;
      }
    }
  }
  cout << dp[N][K] << endl;
}
