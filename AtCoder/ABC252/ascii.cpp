#include <bits/stdc++.h>
using namespace std;

vector<int> getChildren(vector<int> &parents, int self) {
  int n = parents.size();
  vector<int> children(0);
  for (int i=0; i<n; i++) {
    if (parents.at(i) == self) {
      children.push_back(i);
    }
  }
  return children;
}

int getTime(vector<int> &parents, int self) {
  vector<int> children = getChildren(parents, self);
  int n = children.size();
  if (n == 0) {
    return 0;
  }
  int max_time = 0;
  for (int i=0; i<n; i++) {
    int time = getTime(parents, children.at(i));
    if (time > max_time) {
      max_time = time;
    }
  }
  return max_time + 1;
}

int main() {
  int n;
  cin >> n;
  vector<int> parents(n);
  for (int i=0; i<n; i++) cin >> parents.at(i);

  cout << getTime(parents, 0);
}