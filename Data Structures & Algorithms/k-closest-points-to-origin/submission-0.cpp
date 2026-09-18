class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue < pair<int,vector<int> > >  pq;
        vector<vector<int>> ans;

        for(auto a : points){
            int len = pow(a[0],2) + pow(a[1],2);
            pq.push ( {-len,a});
        }

        for(int i = 0;i < k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
