class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        if(nums.size() == 3)
            return max({nums[0] , nums[1], nums[2]});

        return max ( dp(nums,0,nums.size()-2),dp(nums,1,nums.size()-1 ) );   
    }

    int dp( vector<int> &nums, int head, int end){
        vector <int> state;
        int len = end - head + 1;
        state.push_back( nums[head]);
        state.push_back( max (nums[head],nums[head+1]));

        for( int  i = 2; i < len; i++){
            state.push_back( max( state[i-1], state[i-2] + nums[i + head]) );
        }

        return state[len -1];
    }

};

// 最後一個分開討論 
// state1 不偷第一家偷到這家能夠偷到的最多錢
// state2 不偷最後一家的前提下偷到這家能夠偷到的最多錢
// f(n) = max ( f(n-1), f(n-2) + num[n])
