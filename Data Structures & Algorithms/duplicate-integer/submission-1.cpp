class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> freqs{};
        for (int i : nums) {
            if (freqs.contains(i)) {
                return true;
            }
            freqs.insert(i);
        }
        return false;
    }
};