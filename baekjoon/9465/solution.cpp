#include <bits/stdc++.h>
using namespace std;

main() {
  int cases, N;
  int sticker[100001][2] = {0};
  int dp[100001][2] = {0};

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cin >> N;

    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < N; col++) {
       cin >> sticker[col][row];
      }
    }

    dp[1][0] = sticker[0][0];
    dp[1][1] = sticker[0][1];

    for (int n = 2; n <= N; n++) {
      dp[n][0] = max({ dp[n - 1][1], dp[n - 2][1] }) + sticker[n - 1][0];
      dp[n][1] = max({ dp[n - 1][0], dp[n - 2][0] }) + sticker[n - 1][1];
    }

    cout << max({ dp[N][0], dp[N][1] }) << endl;
  }
}
