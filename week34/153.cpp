class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            if (hi == lo+1) return min(nums[lo], nums[hi]);
            int mid = lo + (hi-lo)/2;
            if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi])
                return nums[lo];
            if (nums[lo] <= nums[mid] && nums[mid] >= nums[hi])
                lo = mid;
            else hi = mid;
        }
        return nums[lo];
    }
};