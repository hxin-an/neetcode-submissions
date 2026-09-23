class Solution {
private: 
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int>&state, vector<int> used){
        if(state.size() == nums.size()){
            ans.push_back(state);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(used[i] == 1)
                continue;
            state.push_back(nums[i]);
            used[i] = 1;
            backtrack(nums,ans,state,used);
            used[i] = 0;
            state.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector <int> > ans;
        vector <int> state,used(nums.size(),0);
        backtrack(nums,ans,state,used);
        return ans;
    }
};

// used[i] 紀錄被選過的 然後用continue 機制