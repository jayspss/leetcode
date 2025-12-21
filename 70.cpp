#include <vector>


class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2) { return n; }

        int p_1{2}, p_2{1};
        int p{};

        for (int i = 2; i < n; ++i)
        {
            p = p_1 + p_2;
            p_2 = p_1;
            p_1 = p;
        }

        return p;
    }
};