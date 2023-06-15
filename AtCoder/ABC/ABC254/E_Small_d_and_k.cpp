#include <bits/stdc++.h>
using namespace std;

using int_set = pair<int, unordered_set<int>>;
using graph = unordered_map<int, unordered_set<int>>;

void show_set(unordered_set<int> s) {
  for (int i:s) {
    cout << i << ',';
  }
  cout << endl;
}

void show_graph(graph &g) {
  for (auto it = g.cbegin(); it != g.cend(); it++) {
    cout << it->first << " : ";
    show_set(it->second);
  }
}

unordered_set<int> search(graph &g, int x, int k) {
  if (k==0) {
    return unordered_set<int> {x};
  } else {
    unordered_set<int> ret = {x};
    unordered_set<int> adj = g.at(x);
    for (auto it=adj.begin(); it!=adj.end(); it++) {
      unordered_set<int> adj_adj = search(g, *it, k-1);
      ret.insert(adj_adj.begin(), adj_adj.end());
    }
    // cout << "x:" << x << " k:" << k << " ->";
    // show_set(ret);
    return ret;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  graph g;
  for (int i=1; i<=n; i++) {
    g.insert({int_set{i, {}}});
  }
  for (int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    g.at(a).insert(b);
    g.at(b).insert(a);
  }

  // show_graph(g);

  int q;
  cin >> q;
  for (int i=0; i<q; i++) {
    int x, k;
    cin >> x >> k;
    auto nodes = search(g, x, k);
    cout << accumulate(nodes.begin(), nodes.end(), 0) << endl;
  }
}