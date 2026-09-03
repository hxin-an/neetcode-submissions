class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxFrequency = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;

            maxFrequency = max(
                maxFrequency,
                mp[s[right]]
            );

            while (
                right - left + 1 - maxFrequency > k
            ) {
                mp[s[left]]--;
                left++;
            }

            int windowLength = right - left + 1;
            answer = max(answer, windowLength);
        }

        return answer;
    }
};