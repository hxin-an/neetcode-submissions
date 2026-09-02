class Solution {
public:
    int climbStairs(int n) {
        vector<int> state;
        state.push_back(1);
        state.push_back(2);

        for(int i = 2;i < n;i++){
            state.push_back( state[i-1] + state[i-2]);
        }

        return state[n-1];
    }
};

// 爬到這一格的總次數
// f(n) = f(n-1) + f(n-2)