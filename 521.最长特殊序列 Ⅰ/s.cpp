
class Solution {
public:
    int findLUSlength(string a, string b) {
        int aLen = a.size(), bLen = b.size();
        if (aLen != bLen) return max(aLen, bLen);
        if (a != b) return aLen;
        return -1;
    }
};