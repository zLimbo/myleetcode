#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() { return 0; }

class Solution {
public:
    long long minimumTime(vector<int>& time, int ts) {
        using LL = long long;

        LL lo = 0, hi = (LL)ts * (*min_element(time.begin(), time.end())) + 1;

        while (lo < hi) {
            LL mi = (hi - lo) / 2 + lo;
            LL k = 0;
            for (auto x : time) {
                k += mi / x;
            }
            if (k < ts) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }

        return lo;
    }
};