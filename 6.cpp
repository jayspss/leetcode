#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; }
        vector<string> str(numRows);
        int y = numRows + numRows - 2;
        for (int i = 0; i < s.size(); ++i) {
            auto idx = i % y;
            if (idx < numRows) { str[idx].push_back(s[i]); }
            else { str[y - idx].push_back(s[i]); }
        }
        string res;
        for (auto &x: str) { res.append(x); }
        return res;
    }
};