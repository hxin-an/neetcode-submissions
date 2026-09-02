class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_num = 0, product_sum = 1, product_sum_without_zero = 1; 
        vector <int> ans;

        for ( auto a : nums){
            if ( a == 0){
                zero_num++;
            }else{
                product_sum_without_zero *= a;
            }
            product_sum *= a;
        }
        
        switch (zero_num){
            case 0:
                
                for(auto a : nums){
                    ans.push_back ( product_sum / a );
                }

                break;

            case 1:

                for( auto a : nums){
                    if ( a == 0)
                        ans.push_back( product_sum_without_zero);
                    else
                        ans.push_back(0);
                }

                break;

            default :
                ans.assign(nums.size(),0);
                break;
        }
        return ans;
    }
};
