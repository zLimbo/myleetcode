#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() { return 0; }

class Solution {
public:
    using LL = long long;
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLv(n, -1), minRv(n, n), maxLv(n, -1), maxRv(n, n);
        vector<int> minLq, minRq, maxLq, maxRq;

        for (int i = 0; i < n; ++i) {
            while (!minLq.empty() && nums[i] < nums[minLq.back()]) {
                minRv[minLq.back()] = i;
                minLq.pop_back();
            }
            minLq.push_back(i);
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!minRq.empty() && nums[i] <= nums[minRq.back()]) {
                minLv[minRq.back()] = i;
                minRq.pop_back();
            }
            minRq.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            while (!maxLq.empty() && nums[i] >= nums[maxLq.back()]) {
                maxRv[maxLq.back()] = i;
                maxLq.pop_back();
            }
            maxLq.push_back(i);
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!maxRq.empty() && nums[i] > nums[maxRq.back()]) {
                maxLv[maxRq.back()] = i;
                maxRq.pop_back();
            }
            maxRq.push_back(i);
        }

        LL res = 0;
        for (int i = 0; i < n; ++i) {
            res += (LL)nums[i] * (maxRv[i] - i) * (i - maxLv[i]);
            res -= (LL)nums[i] * (minRv[i] - i) * (i - minLv[i]);
        }

        return res;
    }
};