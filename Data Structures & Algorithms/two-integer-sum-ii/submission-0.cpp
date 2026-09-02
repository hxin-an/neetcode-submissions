class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;

        for( int i = 0; i<nums.size();i++){
            auto it = mp.find( target - nums[i]);
            if (it != mp.end())
                return {it->second, i+1};
            mp[ nums[i] ] = i + 1; 
        }

        return {};
    }
};


// map 存 值 和 指數 比較當前