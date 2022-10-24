#include <bits/stdc++.h>
using namespace std;

int count_report_num(vector<vector<int>> &children, int x) {
  if (children.at(x).size() == 0) {
    return 1;
  }
  int report_num = 1;
  for (int i: children.at(x)) {
    report_num += count_report_num(children, i);
  }
  return report_num;
}

int main() {
  int n;
  cin >> n;
  vector<int> parents(n);
  parents.at(0) = -1;
  for (int i=1; i<n; i++) cin >> parents.at(i);

  vector<vector<int>> children(n);
  for (int i=1; i<n; i++) {
    children.at(parents.at(i)).push_back(i);
  }

  for (int i=0; i<n; i++) {
    cout << count_report_num(children, i) << endl;
  }
}