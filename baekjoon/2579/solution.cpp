#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int num[301] = {0};
  int dp[301] = {0};

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> num[i];
  }
  
  dp[1] = num[1];
  dp[2] = num[1] + num[2];
  dp[3] = max(num[1] + num[3], num[2] + num[3]);

  for (int n = 4; n <= N; n++) {
    dp[n] = max(dp[n - 2] + num[n], dp[n - 3] + num[n - 1] + num[n]);
  }
  cout << dp[N] << endl;
}
