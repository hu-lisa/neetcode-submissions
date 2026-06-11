class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        while (front <= back) {
            if (!isalnum(s[front])) {
                front++;
                continue;
            }
            if (!isalnum(s[back])) {
                back--;
                continue;
            }
            char f = tolower(s[front]);
            char b = tolower(s[back]);
            if (f != b) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};
