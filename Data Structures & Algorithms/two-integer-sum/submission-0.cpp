class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;
        vector <int > ans;
        int key;
        for( int i = 0 ; i < nums.size() ; i++){

            auto ptr = mp.find(nums[i]);
            if (ptr == mp.end()){
                mp.insert( {target - nums[i], i} );
                continue;
            }
            ans.push_back(ptr->second);
            ans.push_back(i);
            
        }
        return ans;
    }
};

