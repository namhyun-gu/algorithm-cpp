#include <iostream>
#include <stack>
using namespace std;

bool dfs(int map[][2]) {
  bool visited[100] = {false};
  stack<int> s;
  bool enable = false;
  int v = 0;
  s.push(0);
  while (!s.empty()) {
    v = s.top();
    visited[v] = true;
    int w = 0;
    for (int i = 0; i < 2; i++) {
      int next = map[v][i];
      if (next != 0 && !visited[next]) {
        w = next;
      }
    }
    if (w == 0) {
      s.pop();
    } else if (w == 99) {
      enable = true;
      break;
    } else {
      s.push(w);
    }
  }
  return enable;
}

int main(int argc, char* argv[]) {
  freopen("input.txt", "r", stdin);
  for (int test_case = 0; test_case < 10;) {
    int data_size;
    cin >> test_case >> data_size;
    int enable = false;
    int map[100][2] = {0};
    for (int i = 0; i < data_size; i++) {
      int src, dest;
      cin >> src >> dest;
      if (map[src][0] != 0) {
        map[src][1] = dest;
      } else {
        map[src][0] = dest;
      }
    }
    enable = dfs(map);
    printf("#%d %d\n", test_case, enable);
  }
  return 0;
}
