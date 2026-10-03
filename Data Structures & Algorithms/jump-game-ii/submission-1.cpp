class Solution {
public:
    int jump(vector<int>& nums) {
        int time = 0, farest = 0, current_end = 0;

        for(int i = 0 ;i<nums.size()-1;i++){
            farest = max(farest,i + nums[i]);
            if( i == current_end){
                time++;
                current_end = farest;
            }
        }

        return time;
    }
};

// step 記錄到每隔的最短步數

