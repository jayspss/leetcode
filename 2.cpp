#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) { return nullptr; }
        auto p1 = l1, p2 = l2;
        auto res = new ListNode(0, nullptr);
        auto p = res;
        int add_next = 0;
        while (p1 != nullptr || p2 != nullptr) {
            if (p1 != nullptr) { p->val += p1->val; }
            if (p2 != nullptr) { p->val += p2->val; }
            p->val += add_next;
            if (p->val > 9) {
                add_next = 1;
                p->val -= 10;
            } else { add_next = 0; }
            bool new_res = false;
            if (p1 != nullptr) { p1 = p1->next; }
            if (p2 != nullptr) { p2 = p2->next; }
            if (p1 != nullptr || p2 != nullptr) {
                p->next = new ListNode;
                p = p->next;
            } else if (add_next != 0) {
                p->next = new ListNode(1, nullptr);
            }
        }
        return res;
    }
};