class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        vector<char> stk{};
        int n = -1;
        unordered_map<char, char> valid{};
        valid['['] = ']';
        valid['('] = ')';
        valid['{'] = '}';
        for (char c : s) {
            if (valid.contains(c)) {
                stk.push_back(c);
                n++;
            } else {
                if (n == -1 || c != valid[stk[n]]) {
                    return false;
                }
                n--;
                stk.pop_back();
            }
        }
        return n == -1;
    }
};
