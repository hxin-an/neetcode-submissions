class Solution {
private:
    void backtrack(vector<int>&cand, int target, vector<vector<int>> &ans, vector<int> & state,int start,int val){
        if( val > target)
            return;
        if(val == target){
            ans.push_back(state);
            return;
        }

        for(int i = start;i<cand.size();i++){
            if (i > start && cand[i] == cand[i - 1])
                continue;
            state.push_back(cand[i]);
            backtrack(cand,target,ans,state,i+1,val+cand[i]);
            state.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector< vector<int> > ans;
        vector < int > state;
        
        sort(cand.begin(),cand.end());
        backtrack(cand,target,ans,state,0,0);
        
        return ans;
    }
};
