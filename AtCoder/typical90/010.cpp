#include<iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int C[N+1], P[N+1];
  for (int i=1; i<=N; i++) cin >> C[i] >> P[i];
  int Q;
  cin >> Q;
  int L[Q], R[Q];
  for (int i=0; i<Q; i++) cin >> L[i] >> R[i];

  // sum[i][j] : i組のj番目までの生徒の点数の和
  int sum[3][N+1];
  for (int i=1; i<=2; i++) sum[i][0] = 0;
  for (int i=1; i<=2; i++) {
    for (int j=1; j<=N; j++) {
      sum[i][j] = sum[i][j-1];
      if (C[j] == i) sum[i][j] += P[j];
    }
  }

  for (int j=0; j<Q; j++) {
    for (int i=1; i<=2; i++) {
      if (i>1) cout << " ";
      cout << sum[i][R[j]] - sum[i][L[j]-1];
    }
    cout << endl;
  }

  return 0;
}