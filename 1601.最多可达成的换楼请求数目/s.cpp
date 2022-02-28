#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() { return 0; }

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = 1 << requests.size();
        vector<vector<int>> dp(m, vector<int>(n));

        int res = 0;
        for (int i = 1; i < m; ++i) {
            int idx = -1, cnt = 0;
            for (int j = 0; j < 32; ++j) {
                if ((i >> j) & 1) {
                    if (idx == -1) idx = j;
                    ++cnt;
                }
            }
            int from = requests[idx][0], to = requests[idx][1];
            int k = i & (i - 1);
            dp[i] = dp[k];
            --dp[i][from];
            ++dp[i][to];

            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (dp[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) res = max(res, cnt);
        }

        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> requests;
    int n;

    vector<int> v;
    int zn;
    int cnt = 0;

    int res = 0;

    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->n = n;
        this->requests = requests;
        this->v = vector<int>(n);
        this->zn = n;

        dfs(0);

        return res;
    }

    void dfs(int cur) {
        if (cur == requests.size()) {
            if (zn == n) {
                res = max(res, cnt);
            }
            return;
        }

        dfs(cur + 1);

        int from = requests[cur][0], to = requests[cur][1];
        int oldZn = zn;

        ++cnt;

        zn -= v[from] == 0;
        --v[from];
        zn += v[from] == 0;

        zn -= v[to] == 0;
        ++v[to];
        zn += v[to] == 0;

        dfs(cur + 1);

        --cnt;
        ++v[from];
        --v[to];
        zn = oldZn;
    }
};

class Solution3 {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n);
        int res = 0, m = requests.size();
        for (int mask = 0; mask < (1 << m); ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt <= res) {
                continue;
            }
            fill(v.begin(), v.end(), 0);
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    ++v[requests[i][0]];
                    --v[requests[i][1]];
                }
            }
            if (all_of(v.begin(), v.end(), [](int x) { return x == 0; })) {
                res = cnt;
            }
        }
        return res;
    }
};