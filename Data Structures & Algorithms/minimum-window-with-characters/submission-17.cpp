class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> target{};
        for (char c : t) {
            target[c]++;
        }
        int windowSum = 0;
        unordered_map<char, int> window{};
        int leftT, rightT;
        int min = INT_MAX;
        int left = 0;
        //move left to exclude filler
        while (!target.contains(s[left])) {
            left++;
            if (left >= s.size()) {
                return "";
            }
        }
        //start right from the left index
        for (int right = left; right < s.size(); right++) {
            //if s[right] is in the target map
            if (target.contains(s[right])) {
                //increment window map's frequency
                window[s[right]]++;
                if (window[s[right]] <= target[s[right]]) {
                    windowSum++; //if we are still "filling" the bucket
                    //increment window sum
                }
                //trim duplicates while keeping window intact
                while (window[s[right]] > target[s[right]]) {
                    if (s[left] == s[right]) {
                        //if we encounter the dupe on the left
                        window[s[left]]--; // trim it
                    } else if (window.contains(s[left])) {
                        //otherwise if it's something else in the window map
                        if (window[s[left]] <= target[s[left]]) {
                            //if we need to keep it in the window, stop the loop
                            break;
                        }
                        //otherwise decrement
                        window[s[left]]--;
                    }
                    //increment left
                    left++;
                }
                //trim filler on left side
                while (!window.contains(s[left]) || window[s[left]] > target[s[left]]) {
                    if (window.contains(s[left])) {
                        window[s[left]]--;
                    }
                    left++;
                }
                //check if the window is complete
                if (windowSum == t.size() && right - left + 1 < min) {
                    min = right - left + 1;
                    leftT = left;
                    rightT = right;
                }
            }
        }
        if (min == INT_MAX) {
            return "";
        }
        string res;
        for (int i = leftT; i <= rightT; i++) {
            res.push_back(s[i]);
        }
        return res;
    }
};
