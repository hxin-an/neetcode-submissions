class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            auto ptr = mp.find(nums[i]);

            if (ptr != mp.end()) {
                return {ptr->second, i};
            }

            mp.insert({target - nums[i], i});
        }

        return {};
    }
};