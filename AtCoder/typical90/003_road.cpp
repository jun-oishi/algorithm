#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> map;

int argmax(vector<int> vec) {
  int max = 0;
  int argmax = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] > max) {
      max = vec[i];
      argmax = i;
    }
  }
  return argmax;
}

void dfs(vector<int> &dist, int from) {
  for (int to: map[from]) {
    if (dist[to] == -1) {
      dist[to] = dist[from] + 1;
      dfs(dist, to);
    }
  }
}

vector<int> searchFarthest(int from) {
  vector<int> dist(n+1, -1);
  dist[from] = 0;
  dfs(dist, from);
  int max_i = argmax(dist);
  int max = dist[max_i];
  return {max_i, max};
}

int main() {
  cin >> n;
  map.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    map[a].push_back(b);
    map[b].push_back(a);
  }

  int from = searchFarthest(1)[0];
  int d = searchFarthest(from)[1];

  cout << d + 1 << endl;

  return 0;
}