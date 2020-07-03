class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (sum == desiredTotal) return maxChoosableInteger % 2;
        unordered_map<int, bool> mem;
        int S = 0;
        function<bool(int, int, int)> dfs = [&](int T, int S, int m) {
            if (mem.find(S) != mem.end()) {
                return mem[S];
            }
            if (m >= T) {
                mem[S] = true;
                return mem[S];
            } else {
                bool res = false;
                int last = 0;
                for (int i = 0; i < maxChoosableInteger; i++) {
                    if ((S & (1 << i)) == 0) {
                        if (m == i + 1) m = last;
                        last = i + 1;
                        if (!dfs(T-i-1, S | (1<<i), m)) {
                            res = true;
                            break;
                        }
                    }
                }
                mem[S] = res;
                return res;
            }
        };
        return dfs(desiredTotal, S, maxChoosableInteger);
    }
};