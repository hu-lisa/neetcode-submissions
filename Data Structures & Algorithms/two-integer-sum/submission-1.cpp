class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> indices{};
        for (int i = 0; i < nums.size(); i++) {
            if (indices.contains(target - nums[i])) {
                res[0] = indices[target - nums[i]];
                res[1] = i;
                break;
            }
            indices[nums[i]] = i;
        }
        return res;
    }
};
