#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> card;

void show(vector<card> cards) {
  int n = cards.size();
  cout << cards[0].first << cards[0].second;
  for (int i = 1; i < n; i++) {
    cout << " " << cards[i].first << cards[i].second;
  }
  cout << endl;
}

vector<card> bubbleSort(vector<card> cards) {
  int n = cards.size();
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (cards[j].second < cards[j-1].second) {
        swap(cards[j], cards[j-1]);
      }
    }
  }
  return cards;
}

vector<card> selectionSort(vector<card> cards) {
  int n = cards.size();
  for (int i = 0; i < n; i++) {
    int mini = i;
    for (int j = i; j < n; j++) {
      if (cards[j].second < cards[mini].second) {
        mini = j;
      }
    }
    swap(cards[i], cards[mini]);
  }
  return cards;
}

vector<card> copyCards(vector<card> source) {
  return source;
}

bool isStable(vector<card> raw_input, vector<card> sorted) {
  int n = raw_input.size();
  // 数字 -> スートの配列 のマップ
  map<int, vector<char> > raw_map;
  map<int, vector<char> > sorted_map;
  for (card p: raw_input) {
    raw_map[p.second].push_back(p.first);
  }
  for (card p: sorted) {
    sorted_map[p.second].push_back(p.first);
  }
  for (pair<int, vector<char> > p: sorted_map) {
    int num = p.first;
    vector<char> raw_suits = raw_map[num];
    vector<char> sorted_suits = sorted_map[num];
    if (raw_suits != sorted_suits) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<card> input_cards(n);
  for (int i = 0; i < n; i++) {
    cin >> input_cards[i].first >> input_cards[i].second;
  }

  vector<card> bubble_sorted(n), selection_sorted(n);
  bubble_sorted = bubbleSort(copyCards(input_cards));
  selection_sorted = selectionSort(copyCards(input_cards));

  show(bubble_sorted);
  cout << (isStable(input_cards, bubble_sorted) ? "Stable" : "Not stable") << endl;

  show(selection_sorted);
  cout << (isStable(input_cards, selection_sorted) ? "Stable" : "Not stable") << endl;
}