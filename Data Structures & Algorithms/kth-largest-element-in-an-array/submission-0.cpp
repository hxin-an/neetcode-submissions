class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int count = 0;
        priority_queue <int> pq;

        for(auto a:nums){
            count++;
            if (count > k){
                if( -pq.top() < a ){
                    pq.pop();
                    pq.push(-a);
                }
            }else{
                pq.push(-a);
            }
        }

        return -pq.top();
    }
};

// 維持一個 k 大小 heap 
// 取負數 這樣 top 是 k 個中最小的
