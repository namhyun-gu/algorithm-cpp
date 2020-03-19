#include <iostream>
using namespace std;

int main() {
  int t, k, n;
  cin >> t;

  int dp[15][15] = {0};

  for (int i = 1; i < 15; i++) {
    dp[0][i] = i;
  }

  for (int h = 1; h < 15; h++) {
    for (int w = 1; w < 15; w++) {
      dp[h][w] += dp[h - 1][w] + dp[h][w - 1];
    }
  }

  while (t > 0) {
    cin >> k >> n;
    cout << dp[k][n] << endl;
    t--;
  }
  return 0;
}
