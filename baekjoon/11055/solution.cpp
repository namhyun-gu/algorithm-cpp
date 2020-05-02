#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, result = 0;
  int num[1001];
  int dp[1001] = {0};

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
    
    dp[i] = num[i];
    for (int j = 0; j < i; j++) {
      if (num[i] > num[j]) {
        dp[i] = max(dp[i], dp[j] + num[i]);
      }
    }
    result = max(result, dp[i]);
  }
  cout << result << endl;
}
