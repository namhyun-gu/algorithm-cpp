#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int wines[10002] = {0};
  int drink[10002] = {0};

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> wines[i];
  }

  drink[1] = wines[1];
  drink[2] = wines[1] + wines[2];

  for (int n = 3; n <= N; n++) {
    drink[n] = max({drink[n - 3] + wines[n] + wines[n - 1], drink[n - 2] + wines[n], drink[n - 1]});
  }

  cout << drink[N] << endl;
}
