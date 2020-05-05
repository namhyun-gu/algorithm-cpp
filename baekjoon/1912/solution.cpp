#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, result = -1001;
  int num[100000];
  int dp[100001];

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }

  for (int i = 1; i <= N; i++) {
    dp[i] = max(dp[i - 1] + num[i - 1], num[i - 1]);
    result = max(result, dp[i]);
  }
  cout << result << endl;
}