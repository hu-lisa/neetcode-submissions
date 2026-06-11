class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (mid < n - 1 && nums[mid + 1] < nums[mid]) {
                return nums[mid + 1];
            }
            if (nums[left] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[0];
    }
};
