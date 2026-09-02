class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1, sum;

        while ( l < r){
            sum = nums[l] + nums[r];

            if ( sum > target )
                r--;
            else if( sum < target)
                l++;
            else
                return { l+1,r+1};

        }

        return {};
    }
};


// map 存 值 和 指數 比較當前