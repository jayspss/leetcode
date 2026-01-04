#include <vector>
#include <algorithm>
#include <cmath>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        auto size = s.size();
        for (int i = 0; i < std::floor(size / 2); ++i)
        {
            std::swap(s[i], s[size - i - 1]);
        }
    }
};