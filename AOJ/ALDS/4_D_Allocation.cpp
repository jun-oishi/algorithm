#include <cstdio>
using namespace std;

int k, n;
int w[1000000];

// 最大積載量がpのときk台のトラックでいくつまで荷物を運べるか
int f(int p) {
  int k_remain = k - 1;
  int loaded = 0;
  for (int i = 0; i < n; i++) {
    if (loaded + w[i] > p) {
      // printf("%d, ", loaded);
      if (k_remain == 0) return i;
      k_remain--;
      if (w[i] > p) return i;
      loaded = 0;
    }
    loaded += w[i];
  }
  // printf("%d, ", loaded);
  return n;
}

int main() {
  scanf("%d %d", &n, &k);
  int total = 0;
  for (int i = 0; i < n; i++) {
    int wi;
    scanf("%d", &wi);
    w[i] = wi;
    total += wi;
  }

  int left = 1;
  int right = total;
  while (left < right) {
    int mid = (left + right) / 2;
    int v = f(mid);
    // printf("f(%d) = %d\n", mid, v);
    if (v >= n) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  printf("%d\n", left);
}