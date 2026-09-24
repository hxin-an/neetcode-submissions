class Solution {
private:
    void backtrack(vector<int>&nums,vector<int>&state,vector<vector<int>>&ans,int start){
        if(start > nums.size())
            return;
        ans.push_back(state);
        if(start == nums.size())
            return;
        for(int i = start;i<nums.size();i++){
            if(i > start and nums[i] == nums[i-1])
                continue;
            state.push_back(nums[i]);
            backtrack(nums,state,ans,i+1);
            state.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> state;
        sort(nums.begin(),nums.end());
        backtrack(nums,state,ans,0);
        return ans;
    }
};
