class Solution {
public:
    int rob(vector<int>& nums) {
        vector <int> state;

        state.push_back(nums[0]);
        if(nums.size() == 1 )
            return nums[0];
        
        state.push_back(max(nums[1],nums[0]));
        if(nums.size() == 2 )
            return state[1];

        state.push_back( max( nums[0]+ nums[2],nums[1]));
        if(nums.size() == 3 )
            return state[2];

        for (int i = 3;i<nums.size();i++){
            state.push_back( max({state[i-2] + nums[i],state[i-3] + nums[i],state[i-1]} ) );
        }
        
        for(auto a:nums)
            cout << a << " ";

        return state[nums.size()-1];
    }
};

// state  偷 i 戶的時候怎麼偷最多的錢
// f(n) = max ( f(n-2) + nums[n], f(n-3) +nums[n], f(n-1) ) 
// 