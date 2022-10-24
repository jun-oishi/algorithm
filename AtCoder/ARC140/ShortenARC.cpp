#include<bits/stdc++.h>
using namespace std;

string replace(string from, int i, string replacement) {
  // i文字目から3文字をreplacementに置き換える
  int n = from.size();
  string replaced = "";
  int c = 0;
  while (c < n) {
    if (c != i) {
      replaced += from.at(c);
      c++;
      continue;
    }
    replaced += replacement;
    c += 3;
  }
  return replaced;
}

int argmin(vector<int> v) {
  int ret = 0;
  int min = v.at(0);
  for (int i=1; i < v.size(); i++) {
    if (v.at(i) < min) {
      ret = i;
      min = v.at(i);
    }
  }
  return ret;
}
int argmax(vector<int> v) {
  int ret = 0;
  int max = v.at(0);
  for (int i=1; i<v.size(); i++) {
    if (v.at(i) > max) {
      ret = i;
      max = v.at(i);
    }
  }
  return ret;
}

string process(string s, int i) {
  int n = s.size();
  int c = 0;
  vector<int> arcbegin;
  vector<int> max_itr;
  int numAbefore = 0;

  while (c < n-2) {
    if (s.at(c) != 'A') {
      c++;
      numAbefore = 0;
      continue;
    }
    if (s.at(c+1) != 'R' || s.at(c+2) != 'C') {
      c++;
      numAbefore++;
      continue;
    }
    
    arcbegin.push_back(c);
    int numCafter = 0;
    while (true) {
      if (c+3+numCafter < n && s.at(c+3+numCafter) == 'C') {
        numCafter++;
        continue;
      } else {
        break;
      }
    }
    max_itr.push_back(min(numAbefore, numCafter));
    numAbefore = 0;
    c += 3;
  }

  if (arcbegin.size() == 0) {
    return s;
  }
  if (i % 2 == 1) {
    return replace(s, arcbegin.at(argmax(max_itr)), "R");
  } else {
    return replace(s, arcbegin.at(argmin(max_itr)), "AC");
  }
}

int main() {
  int n;
  string s;
  cin >> n;
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