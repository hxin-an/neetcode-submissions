class Solution {
private:
    void backtrack ( vector <int> &nums,int target, vector<vector<int>>&ans, vector<int>&state, int val, int start){
        if (val > target)
            return;
        
        if( target == val){
            ans.push_back(state);
            return;
        }

        for(int i = start;i< nums.size();i++){
            state.push_back(nums[i]);
            backtrack( nums, target, ans, state, val + nums[i],i);
            state.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector< vector<int> > ans;
        vector<int> state;
        backtrack( nums, target,ans,state,0,0);
        return ans;
    }
};

// backtrack
// state 陣列裡面的值
// val 紀錄大小