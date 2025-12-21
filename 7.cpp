#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648) { return 0; }
        int v = abs(x);
        string s = to_string(v);
        string sr;
        for (int i = s.size() - 1; i >= 0; --i) {
            sr.push_back(s[i]);
        }
        try {
            v = std::stoi(sr);
        } catch (exception e) {
            return 0;
        }
        if (x < 0) { v = -v; }
        return v;
    }
};

int main() {
    Solution s;
    cout << s.reverse(2047483647);

    return 0;
}