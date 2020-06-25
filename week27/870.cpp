class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res(B.size(), -1), tmp;
        sort(begin(A), end(A));
        multimap<int, int> m;
        for (int i = 0; i < B.size(); i++) m.insert({B[i], i});
        int i = 0;
        for (auto &[n, id] : m) {
            while (i < B.size() && A[i] <= n) {
                tmp.push_back(A[i++]);
            }
            if (i == B.size()) break;
            res[id] = A[i++];
        }
        i = 0;
        for (auto& n : res) if (n < 0) n = tmp[i++];
        return res;
    }
};