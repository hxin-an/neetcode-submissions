class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = -1, l = 0, r = heights.size()-1;

        while ( l < r){
            int width = r - l;
            int height = min(heights[l], heights[r]);
            int area = width * height;

            ans = max(ans, area);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
