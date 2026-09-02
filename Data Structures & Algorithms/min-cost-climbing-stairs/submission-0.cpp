class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector <int> state;

        state.push_back(0);
        state.push_back(0);

        for(int i = 2;i<=cost.size();i++ ){
            state.push_back( min(state[i-1] + cost[i-1], state[i-2] + cost[i-2] ) );
        }
        for(auto a: state){
            cout << a << " ";
        }
        return state[cost.size()]; 
    }
};

// state 是 min cost
// index 0 為 cost
// f(n) = min f(n-1) + c(n-1) , f(n-2) + c(n-2)
