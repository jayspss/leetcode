struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr) { return nullptr; }
        auto p1 = head;
        auto p2 = head;
        ListNode *pre = nullptr;
        for (int i = 0; i < n; ++i)
        {
            p2 = p2->next;
        }
        while (p2 != nullptr)
        {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (pre != nullptr)
        {
            pre->next = p1->next;
            delete p1;
            return head;
        } else
        {
            pre = head->next;
            delete head;
            return pre;
        }
    }
};