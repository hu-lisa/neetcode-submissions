class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //a = 97
        unordered_map<string, vector<string>> buckets{};
        for (auto str : strs) {
            vector<int> freqs(26);
            for (auto c : str) {
                freqs[c - 'a']++;
            }
            string key = to_string(freqs[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(freqs[i]);
            }
            buckets[key].push_back(str);
        }
        vector<vector<string>> res{};
        for (auto pair : buckets) {
            res.push_back(pair.second);
        }
        return res;
    }
};
