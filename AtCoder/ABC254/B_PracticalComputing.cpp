#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> ans = {{1}};
  for (int i=1; i<n; i++) {
    vector<int> new_a = {1};
    vector<int> prev_a = ans.at(i-1);
    for (int j=1; j<i; j++) {
      new_a.push_back(prev_a.at(j-1)+prev_a.at(j));
    }
    new_a.push_back(1);
    ans.push_back(new_a);
  }

  for (int i=0; i<n; i++) {
    vector<int> a = ans.at(i);
    for (int j=0; j<=i; j++) {
      if (j != i) {
        cout << a.at(j) << ' ';
      } else {
        cout << a.at(j);
      }
    }
    cout << endl;
  }
}