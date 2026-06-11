class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            //case 1: all 3 in same sorted segment
            //case 2: mid and right are sorted
            //case 3: mid and left are sorted
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[right] == target) {
                return right;
            }
            if (nums[left] == target) {
                return left;
            }
            if (nums[mid] >= nums[left] && nums[right] < nums[mid]) {
                //mid and left are sorted
                if (nums[left] <= target) {
                    right--;
                } else {
                    left++;
                }
            } else if (nums[mid] <= nums[right] && nums[left] > nums[right]) {
                //mid and right are sorted
                if (nums[right] <= target) {
                    right--;
                } else {
                    left++;
                }
            } else {
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
