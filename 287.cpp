#include <vector>

class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        if (nums.size() == 1) { return nums[0]; }
        int slow_idx = nums[0];
        int fast_idx = nums[nums[0]];
        while (slow_idx != fast_idx)
        {
            slow_idx = nums[slow_idx];
            fast_idx = nums[nums[fast_idx]];
        }
        fast_idx = slow_idx;
        slow_idx = 0;
        while (slow_idx != fast_idx)
        {
            slow_idx = nums[slow_idx];
            fast_idx = nums[fast_idx];
        }
        return slow_idx;
    }
};