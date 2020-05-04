#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, result = 0;
  int num[1001];
  int dp_lis[1001] = {0};
  int dp_lls[1001] = {0};

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];

    dp_lis[i] = 1;
    for (int j = 0; j < i; j++) {
      if (num[i] > num[j]) {
        dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
      }
    }
  }
  
  for (int i = N - 1; i >= 0; i--)  {
    dp_lls[i] = 1;
    for (int j = N - 1; j > i; j--) {
      if (num[i] > num[j]) {
        dp_lls[i] = max(dp_lls[i], dp_lls[j] + 1);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    result = max(result, dp_lis[i] + dp_lls[i] - 1);
  }
  cout << result << endl;
}
