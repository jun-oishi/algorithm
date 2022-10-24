#include <bits/stdc++.h>
using namespace std;

int get_luca(vector<int> computed, int i) {
  int max_i = computed.size() - 1;
  if (i <= max_i) {
    return computed.at(i);
  } else {
    int res = get_luca(computed, i-2) + get_luca(computed, i-1);
    computed.push_back(res);
    return res;
  }
}

int main() {
  int n;
  vector<int> computed = {2, 1};
  cin >> n;
  cout << get_luca(computed, n) << endl;
}