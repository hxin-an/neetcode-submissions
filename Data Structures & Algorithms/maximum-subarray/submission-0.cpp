class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = nums[0];

        for(int i = 1;i<nums.size();i++){
            if(sum > 0){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            if (sum > ans)
                ans = sum;
        }

        return ans;
    }
};

// f(x) = 