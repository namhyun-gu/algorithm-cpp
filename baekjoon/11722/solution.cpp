#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, result = 0;
  int num[1000];
  int dp[1000] = {0};

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num[i];

    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (num[i] < num[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    result = max(result, dp[i]);
  }
  cout << result << endl;
}
