class Solution {
public:
    string makeLargestSpecial(string S) {
        function<string(int,int)> dfs = [&](int s, int t) {
            int count = 0, i = s, j = s;
            vector<string> slices;
            while (j < t) {
                if (S[j] == '1') count++;
                else count--;
                if (count == 0) {
                    slices.push_back("1"+dfs(i+1, j)+"0");
                    i = j+1;
                }
                j++;
            }
            sort(rbegin(slices), rend(slices));
            string r;
            for (auto&& sub : slices) r += sub;
            return r;
        };
        return dfs(0, S.size());
    }
};