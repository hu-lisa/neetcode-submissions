class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& sums, int i) {
        int n = nums.size();
        if (i >= n) {
            return 0;
        }
        int keep = (sums[i+2] > 0) ? sums[i+2] : dfs(nums, sums, i+2);
        int skip = (sums[i+1] > 0) ? sums[i+1] : dfs(nums, sums, i+1);
        sums[i] = max(nums[i] + keep, skip);
        return sums[i];
    }
    int rob(vector<int>& nums) {
        vector<int> sums(nums.size() + 2, -1);
        return dfs(nums, sums, 0);
    }
};
