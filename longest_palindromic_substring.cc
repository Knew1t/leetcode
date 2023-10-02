// Given a string s, return the longest palindromic substring in s.

#include <cmath>
#include <cstddef>
#include <iostream>
#include <set>
using namespace std;
class Solution {
 public:
  string longestPalindrome(string s) {
    string longest_pal{};
    size_t l{0}, r{s.length() - 1};
    if (l == r) return s;
    for (; l < r; ++l) {
      while (l < r) {
        if (s[r] == s[l]) {
          size_t tmp_r{r}, tmp_l{l};
          while (tmp_l < tmp_r) {
            if (s[tmp_l] == s[tmp_r]) {
              ++tmp_l;
              --tmp_r;
              continue;
            } else {
              break;
            }
          }
          if (s[tmp_l] == s[tmp_r]) {
            longest_pal = longest_pal.length() > r - l + 1
                              ? longest_pal
                              : s.substr(l, r - l + 1);
            if (longest_pal.length() == s.length() ||
                longest_pal.length() == s.length() - 1)
              return longest_pal;
          }
        }
        if (l == r - 1) {
          r = s.length() - 1;
          break;
        }
        --r;
      }
    }
    if (longest_pal == "") return s.substr(0, 1);
    return longest_pal;
  }
};

int main() {
  Solution sol;

  string str = "aboba";  //"aboba"
  cout << sol.longestPalindrome(str) << endl;

  str = "bobtenet";  //"tenet"
  cout << sol.longestPalindrome(str) << endl;

  str = "abcdde";// "dd"
  cout << sol.longestPalindrome(str) << endl;

  str = "abacab";  //"bacab"
  cout << sol.longestPalindrome(str) << endl;

  str = "a"; //"a"
  cout << sol.longestPalindrome(str) << endl;

  str = "ac"; //"a"
  cout << sol.longestPalindrome(str) << endl;

  return 0;
}
