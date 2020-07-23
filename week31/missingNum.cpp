class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < nums.size(); i++) if (nums[i] != i) return i;
        return -1;
    }
};