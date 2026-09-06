class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s(nums.begin(), nums.end());
        int ans = 0, curr = 0, count = *s.begin() - 1;

        while ( !s.empty() ){
            auto iter = s.find (count + 1);
            if ( iter != s.end() ) {
                curr += 1;
                count ++;
                s.erase(count);

                if(curr >= ans)
                    ans = curr;
            }else{
                curr = 0;
                count = *s.begin() - 1;
            }
        }


        return ans;
    }
};

// 存進 oreder set  
// 使用 一個變數 存目前最大連續值