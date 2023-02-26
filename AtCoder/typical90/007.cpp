#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi = vector<int>;

int min(int a, int b) { return a>b ? b : a; }

int abs(int a) { return -min(a, -a); }

int main() {
  int N;
  cin >> N;
  vi A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  int Q;
  cin >> Q;
  for (int j=0; j<Q; j++) {
    int B;
    cin >> B;
    // A[i] < B なる最大のiを求める
    int left=0, right=N-1;
    while (right > left + 1) {
      int mid = (left+right)/2;
      if (A[mid] < B) {
        left = mid;
      } else {
        right = mid;
      }
    }
    // cout << "left:" << left << "  right:" << right << " => ";
    int ans;
    if (right == 0) {
      ans = abs(A[0] - B);
    } else if (left == N-1) {
      ans = abs(B - A[N-1]);
    } else {
      ans = min(abs(A[right]-B), abs(B-A[left]));
    }
    cout << ans << endl;
  }
  return 0;
}