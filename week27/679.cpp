class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        function<bool(vector<double>&)> dfs = [&](vector<double>& r) {
            if (r.size() == 1) return abs(r[0] - 24) < 1e-5;
            vector<double> tmp;
            tmp.resize(r.size() - 1);
            for (int i = 0; i < r.size(); i++) {
                for (int j = i+1; j < r.size(); j++) {
                    vector<double> t = {r[i]+r[j], r[i]*r[j], r[i]-r[j], r[j]-r[i]};
                    if (abs(r[i] - 0.0) > 1e-5) t.push_back(r[j]/r[i]);
                    if (abs(r[j] - 0.0) > 1e-5) t.push_back(r[i]/r[j]);
                    int index = 0;
                    for (auto k : t) {
                        tmp[index++] = k;
                        for (int l = 0; l < r.size(); l++) {
                            if (l!=i&&l!=j) tmp[index++] = r[l];
                        }
                        if (dfs(tmp)) return true;
                        index = 0;
                    }
                }
            }
            return false;
        };
        vector<double> t(nums.begin(), nums.end());
        return dfs(t);
    }
};