class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size(), y = nums2.size();
        if (x > y) return findMedianSortedArrays(nums2, nums1);
        int lo = 0, hi = x;
        while (lo <= hi) {
            int px = lo+(hi-lo)/2;
            int py = (x+y+1)/2 - px;
            int maxlx = px == 0 ? INT_MIN : nums1[px-1];
            int maxly = py == 0 ? INT_MIN : nums2[py-1];
            int minrx = px == x ? INT_MAX : nums1[px];
            int minry = py == y ? INT_MAX : nums2[py];
            if (maxlx <= minry && maxly <= minrx) {
                if ((x+y)%2 == 0) return (max(maxlx, maxly)+min(minrx, minry))/2.0;
                else return max(maxlx, maxly);
            } else if (maxlx > minry) hi = px-1;
            else lo = px + 1;
        }
        return 0;
    }
};