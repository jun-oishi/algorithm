#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> h(3);
  cin >> h.at(0) >> h.at(1) >> h.at(2);
  sort(h.begin(), h.end());
  cout << h.at(2) - h.at(0) << endl;
}
