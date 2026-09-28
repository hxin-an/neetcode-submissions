class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        // 第一階段：找到 cycle 裡的相遇點
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // 第二階段：找 cycle entry
        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};