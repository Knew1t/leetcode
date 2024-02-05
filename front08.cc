
#include <iostream>
using namespace std;

static const char examplePuzzle[7][7] = {
    {'b', 'l', 'g', 'o', 'l', 'd', 's'}, {'x', 'k', 'q', 'w', 'i', 'j', 'p'},
    {'a', 'n', 'w', 'k', 'k', 'p', 'n'}, {'h', 'e', 'e', 'e', 'k', 'i', 'l'},
    {'q', 'e', 'k', 'a', 'y', 'q', 'a'}, {'h', 'u', 'h', 'a', 'e', 'a', 'u'},
    {'k', 'q', 'j', 'c', 'c', 'm', 'r'},
};

bool checkAround(const char puzzle[][7], string word, int i, int j) {
  bool result = false;
  int k = 0;
  if (i - 1 >= 0 && j - 1 >= 0) {
    if (puzzle[i - 1][j - 1] == word[k]) {
    }
  }
  return result;
};
bool searchSubstring(const char puzzle[][7], string word) {
  bool result = false;
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      if (puzzle[i][j] == word[0]) {
      }
    }
  }
  return result;
};

int main() {
  string word = "like";
  cout << searchSubstring(examplePuzzle, word) << endl;
  return 0;
}
