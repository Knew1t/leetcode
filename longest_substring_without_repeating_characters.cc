#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> used_chars;
    int max{0}, count{0};
    int left{0}, right{0};
    for (; right < s.length(); ++right) {
      if (used_chars.count(s[right]) == 0) {
        used_chars.insert(s[right]);
      } else {
        while (used_chars.count(s[right])) {
          used_chars.erase(s[left]);
          ++left;
       }
        used_chars.insert(s[right]);
      }
      count = right - left + 1;
      max = count > max ? count : max;
    }
    return max;
  }
};
int main() {
  Solution s;
  string str = "abcabcbb";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << " correct -> 3" << endl;
  str = "bbb";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = "pwwkew";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = " ";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = "au";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = "aab";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = "dvdf";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = "anviaj";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;
  str = "ckilbkd";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << endl;

  str = "wobgrovw";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << " correct -> 6" << endl;

  str = "bpfbhmipx";
  cout << "\"" << str << "\"" << endl;
  cout << s.lengthOfLongestSubstring(str) << " correct -> 7" << endl;

  return 0;
}
