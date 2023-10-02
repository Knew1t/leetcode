#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <list>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result_list{nullptr}, *t1{l1}, *t2{l2};
    int carry{0};
    while (t1 != nullptr || t2 != nullptr) {
      int val1{(t1 == nullptr) ? 0 : t1->val};
      int val2{(t2 == nullptr) ? 0 : t2->val};
      ListNode *tmp{new ListNode{val1 + val2 + carry}};
      if (tmp->val >= 10) {
        carry = 1;
        tmp->val = (tmp->val == 10) ? 0 : tmp->val % 10;
      } else {
        carry = 0;
      }

      if (result_list) {
        appendToList(result_list, tmp);
      } else {
        result_list = tmp;
      }
      t1 = t1 == nullptr ? nullptr : t1->next;
      t2 = t2 == nullptr ? nullptr : t2->next;
      if (t1 == nullptr && t2 == nullptr && carry == 1) {
        ListNode *last{new ListNode{1}};
        tmp->next = last;
      }
    }
    return result_list;
  };

private:
  void appendToList(ListNode *list, ListNode *node) {
    ListNode *tmp{list};
    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    tmp->next = node;
  }
};

void appendToList(ListNode *list, ListNode *node) {
  ListNode *tmp{list};
  while (tmp->next != nullptr) {
    tmp = tmp->next;
  }
  tmp->next = node;
}

void fillList(ListNode **list, std::initializer_list<int> inc) {
  for (auto it : inc) {
    if (*list) {
      ListNode *new_node = new ListNode{it};
      appendToList(*list, new_node);
    } else {
      *list = new ListNode{it};
    }
  }
}

void printlist(ListNode *list) {
  ListNode *tmp = list;
  while (tmp) {
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
  std::cout << std::endl;
}

int main() {
  // ListNode *l1{new ListNode{2, new ListNode{4, new ListNode{3, nullptr}}}};
  // ListNode *l2{
  //     new ListNode{5, new ListNode{6 /*, new ListNode{4, nullptr} */}}};
  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;
  // fillList(&l1, {2, 3, 4});
  // fillList(&l2, {5, 6, 4});
  fillList(&l1, {9, 9});
  fillList(&l2, {9});
  printlist(l1);
  printlist(l2);
  Solution s;
  printlist(s.addTwoNumbers(l1, l2));
  return 0;
}
