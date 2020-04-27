#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v;
  v.reserve(n);
  for (int i = 0; i < n; i++) {
    int input;
    scanf("%d", &input);
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  for (auto &i : v) {
    printf("%d\n", i);
  }
  return 0;
}