#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 1) { return {"()"}; }
        else if (n == 2) { return {"()()", "(())"}; }
        else if (n == 3) { return {"((()))", "(()())", "(())()", "()(())", "()()()"}; }
        auto d = generateParenthesis(n - 1);
        std::set<string> big_s;
        for (auto &x: d)
        {
            string str;
            str.resize(x.size() + 2);
            for (int i = 0; i < x.size(); ++i)
            {
                for (int j = 0; j < i; ++j) { str[j] = x[j]; }
                str[i] = '(';
                str[i + 1] = ')';
                for (int j = i + 2; j < str.size(); ++j) { str[j] = x[j - 2]; }
                big_s.insert(str);
            }
        }
        vector<string> res;
        res.reserve(big_s.size());
        for (auto &x: big_s) { res.emplace_back(x); }
        return res;
    }
};