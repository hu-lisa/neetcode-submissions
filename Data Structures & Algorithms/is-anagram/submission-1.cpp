class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqs{};
        for (char c : s) {
            freqs[c]++;
        }
        for (char c : t) {
            if (!freqs.contains(c)) {
                return false;
            }
            freqs[c]--;
            if (freqs[c] == 0) {
                freqs.erase(c);
            }
        }
        return freqs.size() == 0;
    }
};
