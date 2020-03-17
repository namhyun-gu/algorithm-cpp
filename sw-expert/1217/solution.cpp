#include <iostream>
using namespace std;

int power(int n, int m) {
  if (m == 0) return 1;
  return n * power(n, m - 1);
}

int main(int argc, char* argv[]) {
  freopen("input.txt", "r", stdin);
  for (int test_case = 0; test_case < 10;) {
    cin >> test_case;
    int n, m;
    cin >> n >> m;
    printf("#%d %d\n", test_case, power(n, m));
  }
  return 0;
}
