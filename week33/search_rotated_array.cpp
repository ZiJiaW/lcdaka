class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (r > 0 && nums[r-1] == nums[0]) r--;
        if (r == 0) return nums[0] == target ? 0 : -1;
        while (l < r) {
            mid = l+(r-l)/2;
            if (nums[mid] == target) {
                while (mid >= 0 && nums[mid] == target)
                    mid--;
                return mid+1;
            }
            if (nums[mid] > nums[l]) {
                if (target < nums[mid] && target >= nums[l]) r = mid;
                else l = mid + 1;
            } else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target < nums[l]) l = mid + 1;
                else r = mid;
            } else l++;
        }
        return -1;
    }
};