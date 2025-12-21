#include <vector>
#include <set>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::vector<std::vector<int>> res;
        if (intervals.empty()) { return res; }
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &p1, std::vector<int> &p2) {
            return p1[0] < p2[0];
        });
        for (auto &interval: intervals)
        {
            if (res.empty() || res.back()[1] < interval[0]) { res.push_back(interval); }
            else
            {
                res.back()[1] = std::max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};