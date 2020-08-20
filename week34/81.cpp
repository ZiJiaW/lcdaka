class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = l+(r-l)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[l]) {
                if (target < nums[mid] && target >= nums[l]) r = mid;
                    else l = mid + 1;
                } else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target < nums[l]) l = mid + 1;
                    else r = mid;
                } else l++;
        }
        return false;
    }
};