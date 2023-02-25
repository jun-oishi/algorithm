#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, l, k;
vector<int> a;

bool canAchieve(int score) {
  int cnt = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] - prev >= score && l - a[i] >= score) {
      cnt++;
      prev = a[i];
    }
  }
  if (cnt >= k) return true;
  else return false;
}

int main() {
  cin >> n >> l >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int left = 0;
  int right = 1 + l/(k+1);
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (canAchieve(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;

  return 0;
}