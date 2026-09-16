class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;

        for (auto a: nums){
            sum ^= a;
        }
        return sum;
    }
};
