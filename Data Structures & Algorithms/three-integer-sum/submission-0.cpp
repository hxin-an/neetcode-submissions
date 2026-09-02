class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        vector < vector <int> > ans;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // 避免相同的第一個數字
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    // 避免相同的第二個數字
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }

                    // 避免相同的第三個數字
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};
