class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);
        int d = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            d ^= arr[i];
            if (m.find(d) != m.end()) for (auto t : m[d]) res += i-t-1;
            m[d].push_back(i);
        }
        return res;
    }
};