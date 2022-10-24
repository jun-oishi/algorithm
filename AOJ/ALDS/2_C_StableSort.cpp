#include <bits/stdc++.h>
using namespace std;
using card = pair<char, int>;

void show(card sorted[], int n) {
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << sorted[i].first << sorted[i].second;
  }
  cout << endl;
}

void bubbleSort(card cards[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (cards[j].second < cards[j-1].second) {
        swap(cards[j], cards[j-1]);
      }
    }
  }
  return;
}

void selectionSort(card cards[], int n) {
  for (int i = 0; i < n; i++) {
    int mini = i;
    for (int j = i; j < n; j++) {
      if (cards[j].second < cards[mini].second) {
        mini = j;
      }
    }
    swap(cards[i], cards[mini]);
  }
  return;
}

void copyCards(card source[], card dest[], int n) {
  for (int i = 0; i < n; i++) {
    dest[i] = source[i];
  }
  return;
}

bool isStable(card input[], card output[], int n) {
  // fixme
  bool ret = true;
  for (int i = 1; i < n; i++) {
    if (output[i].second != output[i-1].second) continue;
    for (int j = 0; j < n; j++) {
      if (
        input[j].second == output[i-1].second
        && input[j].first != output[i-1].first
      ) {
        ret = false;
        break;
      }
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  card cards[n];
  for (int i = 0; i < n; i++) {
    cin >> cards[i].first >> cards[i].second;
  }

  card bubble[n], selection[n];
  copyCards(cards, bubble, n);
  copyCards(cards, selection, n);

  bubbleSort(bubble, n);
  show(bubble, n);
  cout << (isStable(cards, bubble, n) ? "Stable" : "Not stable") << endl;

  selectionSort(selection, n);
  show(selection, n);
  cout << (isStable(cards, selection, n) ? "Stable" : "Not stable") << endl;
}