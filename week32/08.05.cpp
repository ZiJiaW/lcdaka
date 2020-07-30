class Solution {
public:
    int multiply(int A, int B) {
        if (B == 0) return 0;
        return B&1 ? A + (multiply(A, B>>1)<<1) : (multiply(A, B>>1)<<1);
    }
};