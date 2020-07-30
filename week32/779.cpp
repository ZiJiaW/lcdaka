class Solution {
public:
    int kthGrammar(int N, int K) {
        // f n k depends on f n-1 k/2
        if (N == 1) return 0;
        if (kthGrammar(N-1, (K+1)/2) == 0) {
            return K&1 ? 0 : 1;
        } else {
            return K&1 ? 1 : 0;
        }
    }
};