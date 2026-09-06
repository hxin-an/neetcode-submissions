class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, len = height.size();
        vector<int> l, r;

        l.push_back(height[0]);
        r.push_back(height[len - 1]);

        for (int i = 1; i < len; i++) {
            // 從左往右記錄最大值
            l.push_back(max(height[i], l[i - 1]));

            // 從右往左記錄最大值
            r.push_back(max(height[len - 1 - i], r[i - 1]));
        }

        // r 現在是由右往左，需要翻轉
        reverse(r.begin(), r.end());

        for (int i = 0; i < len; i++) {
            sum += max(min(l[i], r[i]) - height[i], 0);
        }

        return sum;
    }
};