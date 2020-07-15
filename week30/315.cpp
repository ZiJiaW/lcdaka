class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> idx(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) idx[i] = i;
        vector<int> tmp;
        function<void(int,int)> mergeSort = [&](int i, int j) {
            if (j-i < 1) return;
            int mid = i + (j-i)/2;
            mergeSort(i, mid);
            mergeSort(mid+1, j);
            tmp.clear();
            int p = i, q = mid+1;
            while (p <= mid && q <= j) {
                if (nums[idx[p]] > nums[idx[q]]) {
                    res[idx[p]] += j-q+1;
                    tmp.push_back(idx[p++]);
                } else {
                    tmp.push_back(idx[q++]);
                }
            }
            while (q <= j) tmp.push_back(idx[q++]);
            while (p <= mid) tmp.push_back(idx[p++]);
            copy(tmp.begin(), tmp.end(), idx.begin()+i);
        };
        mergeSort(0, nums.size() - 1);
        return res;
    }
};