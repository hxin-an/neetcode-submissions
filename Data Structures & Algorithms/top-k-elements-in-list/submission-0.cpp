class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map < int , int > mp;
        priority_queue<pair<int, int>> pq;
        vector < int> ans;

        for (int i = 0 ; i < nums.size(); i++){
            mp[ nums[i] ]++;
        }

        for (auto & [num, freq] : mp){
            pq.push({freq,num});
        }

        for ( int i = 0 ; i < k ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};


//  1. 統計每個元素 數量
// 2.  找出k 個最大的 frequent