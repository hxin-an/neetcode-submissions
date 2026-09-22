class Solution {
private:
    vector<vector<int> > ans;
    
    void backtrack (vector<int> &nums, int start, vector <int> &state){
        ans.push_back(state);

        for(int i = start;i<nums.size();i++){
            state.push_back(nums[i]);
            backtrack(nums,i+1,state);
            state.pop_back();         
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> state;
        backtrack(nums, 0, state);
        return ans;
    }
};



