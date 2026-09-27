class Solution {
private:
    void backtrack(vector<string> &ans,string& state, int n,int l,int r){
        if(state.size() == 2*n){
            ans.push_back(state);
            return;
        }
        
        if(l<n){
            state.push_back('(');
            backtrack(ans,state,n,l+1,r);
            state.pop_back();
        }

        if(r<l){
            state.push_back(')');
            backtrack(ans,state,n,l,r+1);
            state.pop_back();           
        }
        return;

    }    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string state;

        backtrack(ans,state,n,0,0);
        return ans;
    }
};

// state 括號  for 左括號數量 < n 或 stack 仍非空