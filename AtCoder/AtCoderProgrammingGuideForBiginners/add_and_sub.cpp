#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int sum = 1;
    for (int i=0; i<n; i++) {
        if (i%2 == 0) {
            continue;
        }
        if (s.at(i) == '+') {
            sum++;
        } else {
            sum--;
        }
    }
    cout << sum;
}
