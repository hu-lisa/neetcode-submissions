class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_set<char> chars{};
        int res = 0;
        while (right < s.size()) {
            if (chars.contains(s[right])) {
                while(s[left] != s[right]) {
                    chars.erase(s[left]);
                    left++;
                }
                chars.erase(s[left]);
                left++;
            } else {
                chars.insert(s[right]);
                right++;
                res = max(res, right - left);
            }
        }
        return res;
    }
};
