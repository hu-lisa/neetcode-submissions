class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int front = 0;
        int back = heights.size() - 1;
        while (front < back) {
            int volume = min(heights[front], heights[back]) * (back - front);
            if (volume > max) {
                max = volume;
            }
            if (heights[front] < heights[back]) {
                front++;
            } else {
                back--;
            }
        }
        return max;
    }
};
