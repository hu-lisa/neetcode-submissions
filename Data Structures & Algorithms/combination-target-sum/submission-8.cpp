class Solution {
public:
    void combo(vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& res, int index) {
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] < target) {
                path.push_back(nums[i]);
                combo(nums, target - nums[i], path, res, i);
                path.pop_back();
            }
            if (nums[i] == target) {
                path.push_back(nums[i]);
                res.push_back(path);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        combo(nums, target, path, res, 0);
        return res;
    }
};
