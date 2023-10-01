// Given two sorted arrays nums1 and nums2 of size m and n respectively, return
// the median of the two sorted arrays.
//
// The overall run time complexity should be O(log (m+n)).
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    list<int> merged;
    int i = 0, j = 0;
    for (; i < nums1.size() && j < nums2.size();) {
      if (nums1[i] < nums2[j]) {
        merged.push_back(nums1[i++]);
      } else {
        merged.push_back(nums2[j++]);
      }
    }
    if (i == nums1.size()) {
      while (j < nums2.size()) {
        merged.push_back(nums2[j++]);
      }
    } else {
      while (i < nums1.size()) {
        merged.push_back(nums1[i++]);
      }
    }
    if (merged.size() % 2 == 0) {
      int count{0};
      for (list<int>::iterator it = merged.begin(); it != merged.end(); ++it) {
        if (count++ != merged.size() / 2-1)
          continue;
        return ((*it) + (*(++it))) / 2.0;
      }

    } else {
      int count{0};
      for (auto it : merged) {
        if (count++ != merged.size() / 2)
          continue;
        return it;
      }
    }
    // PrintList(merged);
    return 0;
  }
  void PrintList(list<int> &merged) {
    for (auto it : merged) {
      cout << it << " ";
    }
    cout << endl;
  }
};

int main() {
  Solution sol;
  vector<int> nums1{1, 3, 5, 7};
  vector<int> nums2{2, 4, 8, 9, 15};
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

  nums1 = {1, 3};
  nums2 = {2};
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

  nums1 = {1, 2};
  nums2 = {3, 4};
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
