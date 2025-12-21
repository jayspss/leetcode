#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        auto size = s.size();
        int res{};
        for (int i = 0; i < size; ++i)
        {
            for (int j = i; j < size; ++j)
            {
                int l = i, r = j;
                while (l <= r && (s[l] == s[r]))
                {
                    l++;
                    r--;
                }
                if (l > r) { res++; }
            }
        }
        return res;
    }
};