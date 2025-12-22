#include <vector>
#include <unordered_map>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        int size = nums.size();
        int pre_sum{};
        int res{};
        std::unordered_map<int, int> c;
        c[0]++;
        for (int i = 0; i < size; ++i)
        {
            pre_sum += nums[i];
            if (c.find(pre_sum - k) != c.end()) { res += c[pre_sum - k]; }
            c[pre_sum]++;
        }
        return res;
    }
/*
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        std::vector<int> pre_sum(size + 1, 0);
        for (int i = 1; i < size + 1; ++i)
        {
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        }
        int res{};
        for (int i = 0; i < size; ++i)
        {
            for (int j = i; j < size; ++j)
            {
                if ((pre_sum[j + 1] - pre_sum[i]) == k) { res++; }
            }
        }
        return res;
    }
    */
};