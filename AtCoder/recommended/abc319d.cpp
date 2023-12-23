#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long l[200001];

long long compute(long long w) {
  long long cur = l[0];
  long long lines = 1;
  for (long long i = 1; i < n; i++) {
    cur += 1 + l[i];
    if (cur > w) {
      if (l[i] > w) {
        lines = -1;
        break;
      }
      cur = l[i];
      lines++;
    }
  }
  return lines;
}

int main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> l[i];

  long long s = 0;
  long long l_max = 0;
  for (long long i = 0; i < n; i++) {
    s += l[i];
    l_max = max(l_max, l[i]);
  }

  long long left = l_max, right = s + n - 1;
  while (left + 1 < right) {
    long long mid = (left + right) / 2;
    long long f = compute(mid);
    if (f < 0) {
      cout << "left < max word length" << endl;
      exit(1);
    } else if (f > m) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << right << endl;

  return 0;
}