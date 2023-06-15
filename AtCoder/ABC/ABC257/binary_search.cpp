#include <bits/stdc++.h>
using namespace std;

// sup未満で最大最後の要素のindexを返す
// sorted[0]>=supなら-1を返す
int binary_search(int sup, vector<int> &sorted) {
  int left = -1, right = sorted.size();
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (sorted[mid] >= sup) {
      right = mid; // つねにsorted[right] >= sup || right==sorted.size()
    } else {
      left = mid; // つねにsorted[left] < sup
    }
  }
  // ここで left=right-1
  return left;
}

int main() {
  vector<int> v = {1, 1, 2, 3, 3, 3, 4};
  for (int i=0; i<6; i++) {
    cout << i << " -> " << binary_search(i, v) << endl;
  }
}