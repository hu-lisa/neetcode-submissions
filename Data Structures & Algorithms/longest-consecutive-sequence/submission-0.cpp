class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset(nums.begin(), nums.end());
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!nset.contains(nums[i] - 1)) {
                int temp = nums[i];
                int count = 1;
                while (nset.contains(temp + 1)) {
                    temp++;
                    count++;
                }
                if (count > max) {
                    max = count;
                }
            }
        }
        return max;
    }
};
