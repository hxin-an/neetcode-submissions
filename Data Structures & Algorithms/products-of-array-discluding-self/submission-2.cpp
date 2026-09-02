class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int len = nums.size();
        vector < int >  prefix( len ), postfix( len ), ans ;
    
        prefix [0] = 1;
        postfix [ len - 1] = 1;

        for ( int i = 1 ; i < len ; i++ ){
            prefix[i] = prefix[i-1] * nums[i-1];
            postfix [len - i - 1] = postfix [len - i] * nums[len - i]; 
        } 

        for ( int  i = 0; i<len; i++){
            ans.push_back( postfix[i] * prefix[i] );
        }
        return ans;
    
    }
};
