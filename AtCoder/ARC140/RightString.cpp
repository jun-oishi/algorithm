#include<bits/stdc++.h>
using namespace std;

int f(string s) {
  int n = s.size();
  for (int m=0; m<=n/2+1; m++) {
    if (n%m != 0) continue;
    int d = n/m;
    for (int i=0; i<m; i++) {
      bool ;
      for (int j=0; j<d; j++) {
        if (s.at(j+i*m) == s.at(i)) {
          is_ok = false;
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  int i = 0;
  string processed;
  while (true) {
    processed = process(s, i);
    if (processed == s) {
      break;
    } else {
      s = processed;
      i++;
      continue;
    }
  }
  cout << i << endl;
}