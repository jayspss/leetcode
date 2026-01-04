#include <vector>
#include <cmath>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int max_val{nums[0]};
        int dp = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp = std::max(dp + nums[i], nums[i]);
            max_val = std::max(dp, max_val);
        }
        return max_val;
    }
};