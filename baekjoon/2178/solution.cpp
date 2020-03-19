#include <stdio.h>

#include <queue>
using namespace std;

int miro[101][101];
int visit[101][101];
int visit_depth[101][101];
int min_depth = 10000;

int dir_x[] = {1, 0, -1, 0};
int dir_y[] = {0, 1, 0, -1};

void traversal(int dest_x, int dest_y) {
  int x, y;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  visit[0][0] = true;
  visit_depth[0][0] = 1;

  while (!q.empty()) {
    pair<int, int> front = q.front();
    x = front.first;
    y = front.second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int dx = x + dir_x[i];
      int dy = y + dir_y[i];

      if (miro[dy][dx] && !visit[dy][dx]) {
        visit[dy][dx] = true;
        visit_depth[dy][dx] = visit_depth[y][x] + 1;
        q.push(make_pair(dx, dy));
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int N, M;
  char line[102];
  scanf("%d %d", &N, &M);
  for (int col = 0; col < N; col++) {
    scanf("%s", line);
    for (int row = 0; row < M; row++) {
      miro[col][M - 1 - row] = line[M - 1 - row] - 48;
    }
  }
  traversal(M - 1, N - 1);
  printf("%d\n", visit_depth[N - 1][M - 1]);
  return 0;
}