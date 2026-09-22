class KthLargest {
private:
    priority_queue <int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto a:nums){
            if (pq.size() < k)
                pq.push(-a);
            else{
                if(-pq.top() < a ){
                    pq.pop();
                    pq.push(-a);
                }
            }
        }
    }
    int add(int val) {
        if (pq.size() < k) {
            pq.push(-val);
        }
        else if (-pq.top() < val) {
            pq.pop();
            pq.push(-val);
        }

        return -pq.top();
    }
};
