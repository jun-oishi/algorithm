#include <bits/stdc++.h>
using namespace std;

void show(int n, int arr[]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << arr[i * n + j];
    }
    cout << endl;
  }
}

void showPath(int n, int path[], int flow) {
  for (int i = 0; i < n; i++) {
    if (path[i] == -1) break;
    if (i) cout << " -> ";
    cout << path[i];
  }
  cout << " : " << flow << endl;
  return;
}

void initializeR(int n, int ans[], int R[], const int D[]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (D[i * n + j] > 0)
        R[i * n + j] = D[i * n + j] - ans[i * n + j];
      else
        R[i * n + j] = ans[j * n + i];
    }
  }
}

int search(int n, const int R[], int path[], int in) {
  showPath(n, path, in);
  int cp = 0, tail;
  int visited[n];
  for (int i = 0; i < n; i++) visited[i] = 0;
  for (tail = 0; tail < n; tail++) {
    if (path[tail] >= 0) {
      visited[path[tail]] = 1;
      cp = path[tail];
    } else {
      break;
    }
  }
  if (cp == n - 1) return in;
  int out = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    out = R[cp * n + i];
    if (out > 0) {
      path[tail] = i;
      if (out > in) out = in;
      if (i == n - 1) break;
      int tmp = search(n, R, path, out);
      if (tmp > 0) {
        out = tmp;
      } else {
        continue;
      }
    }
  }
  return out;
}

bool update(int n, int ans[], int R[]) {
  // i番目に通る節をpath[i]にいれる
  int path[n];
  for (int i = 0; i < n; i++) path[i] = -1;
  path[0] = 0;
  int flow = search(n, R, path, 1e9);
  if (flow == 0) return false;
  bool reachSink = false;
  for (int i = 0; i < n; i++) {
    if (path[i] == n - 1) {
      reachSink = true;
      break;
    }
  }
  if (!reachSink) return false;
  cout << "path:";
  for (int i = 0; i < n; i++) cout << " " << path[i];
  cout << " flow:" << flow << endl;
  for (int i = 1; i < n; i++) {
    int from = path[i - 1];
    int to = path[i];
    if (to < 0) break;
    if (ans[to * n + from] > 0) {
      ans[to * n + from] -= flow;
      R[to * n + from] += flow;
      R[from * n + to] -= flow;
    } else {
      ans[from * n + to] += flow;
      R[to * n + from] += flow;
      R[from * n + to] -= flow;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  // i->jの弧の重みをD[i*n+j]に入れる
  int D[n * n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> D[i * n + j];
  }

  // Rを更新して解をつくる
  int ans[n * n];
  int R[n * n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) ans[i * n + j] = 0;
  }

  initializeR(n, ans, R, D);
  while (update(n, ans, R)) {
  }
  cout << "ans" << endl;
  show(n, ans);
  cout << "R" << endl;
  show(n, R);

  int flow = 0;
  for (int i = 0; i < n; i++) flow += ans[0 * n + i];
  cout << flow << endl;
}