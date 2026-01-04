
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) { return nullptr; }
        auto slow_p = head->next;
        auto fast_p = head->next->next;
        while (slow_p != fast_p && fast_p != nullptr)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
            if (fast_p == nullptr) { break; }
            fast_p = fast_p->next;
        }
        if (fast_p == nullptr) { return nullptr; }
        fast_p = slow_p;
        slow_p = head;
        while (fast_p != slow_p)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
        return slow_p;
    }
};