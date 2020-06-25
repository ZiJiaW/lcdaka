class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
                if (cnt[A[i]]++ < i) return -1;
            } else {
                bool f1 = cnt[A[i]]++ < i;
                bool f2 = cnt[B[i]]++ < i;
                if (f1 && f2) return -1;
            }
        }
        int n = cnt[A[0]] == A.size() ? A[0] : B[0];
        int t1 = count(A.begin(), A.end(), n);
        int t2 = count(B.begin(), B.end(), n);
        return A.size() - max(t1, t2);
    }
};