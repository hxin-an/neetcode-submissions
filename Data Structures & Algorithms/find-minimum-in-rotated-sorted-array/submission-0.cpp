class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, mid , min_num = INT_MAX;

        while ( l<=r ){
            mid = l + (r-l)/2;
            
            if ( nums[mid] < min_num)
                min_num = nums[mid];

            if (nums[mid] > nums[r])
                l = mid + 1;
            else 
                r = mid -1;
        }

        return min_num;
    }
};


// 核心邏輯 mid 在大的左段 還是小的右斷
// mid > nums[r] 在大的左段
// mid < nums[r] 在小的右段

