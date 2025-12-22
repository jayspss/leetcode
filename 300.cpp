#include <vector>


class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        auto size = nums.size();
        if (size == 1) { return 1; }
        std::vector<int> len(size, 1);
        int max_num = 1;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) { len[i] = std::max(len[i], len[j] + 1); }
            }
            max_num = std::max(max_num, len[i]);
        }
        return max_num;
    }
};