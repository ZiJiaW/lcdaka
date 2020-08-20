class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> res;
        int lo = 0, hi = arr.size()-1;
        while (lo+1 < hi) {
            int mid = lo+(hi-lo)/2;
            if (arr[mid] > x) hi = mid;
            else lo = mid;
        }
        while (res.size() < k) {
            if (lo == -1) res.push_back(arr[hi++]);
            else if (hi == arr.size()) res.push_front(arr[lo--]);
            else if (abs(arr[lo]-x) <= abs(arr[hi]-x)) res.push_front(arr[lo--]);
            else res.push_back(arr[hi++]);
        }
        return vector<int>(begin(res), end(res));
    }
};