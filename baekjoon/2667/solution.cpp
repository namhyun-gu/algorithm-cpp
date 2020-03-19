#include <stdio.h>

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int map[25][25];
int visit[25][25];
int num[25][25];

int dir_x[] = {1, 0, -1, 0};
int dir_y[] = {0, 1, 0, -1};

int bfs(int x, int y, int n, int number) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visit[y][x] = true;
  num[y][x] = number;

  int cnt = 1;
  while (!q.empty()) {
    pair<int, int> front = q.front();
    int x = front.first;
    int y = front.second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int dx = x + dir_x[i];
      int dy = y + dir_y[i];

      if (dx < 0 || dx >= n) continue;
      if (dy < 0 || dy >= n) continue;

      if (!visit[dy][dx] && map[dy][dx]) {
        visit[dy][dx] = true;
        num[dy][dx] = number;
        q.push(make_pair(dx, dy));
        cnt++;
      }
    }
  }
  return cnt;
}

main() {
  int N;
  char line[26];
  scanf("%d", &N);
  for (int y = 0; y < N; y++) {
    scanf("%s", line);
    for (int x = 0; x < N; x++) {
      map[y][x] = line[x] - '0';
    }
  }

  int number = 1;
  vector<int> num_cnts;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (!visit[y][x] && map[y][x]) {
        int cnt = bfs(x, y, N, number);
        num_cnts.push_back(cnt);
        number++;
      }
    }
  }

  sort(num_cnts.begin(), num_cnts.end());
  printf("%d\n", num_cnts.size());
  for (int i = 0; i < num_cnts.size(); i++) {
    printf("%d\n", num_cnts[i]);
  }
  return 0;
}