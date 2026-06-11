class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> freqs{};
        for (auto i : nums) {
            freqs[i]++;
        }
        for (auto pair : freqs) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> res{};
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                k--;
                if (k == 0) {
                    return res;
                }
            }
        }
        return res;
    }
};
