class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) return {};
        set<int> res;
        for (int i = 0; i <= k; i++) {
            res.insert(i*shorter+(k-i)*longer);
        }
        return vector<int>(begin(res), end(res));
    }
};