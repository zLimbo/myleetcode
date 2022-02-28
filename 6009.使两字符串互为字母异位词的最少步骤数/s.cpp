#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() { return 0; }

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vs(26), vt(26);
        for (auto c : s) ++vs[c - 'a'];
        for (auto c : t) ++vt[c - 'a'];

        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += abs(vs[i] - vt[i]);
        }
        return res;
    }
};