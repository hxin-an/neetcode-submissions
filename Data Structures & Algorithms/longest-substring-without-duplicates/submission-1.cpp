class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int l = 0 ,r = 0 , max_size = 0;
        unordered_set <char> st;

        for (int i = 0; i < len;i++){

            while ( st.count( s[i]) ){
                st.erase (s[l]);
                l++;
            }

            st.insert(s[i]);
            r++;

            int lenth = r - l;
            if( lenth > max_size)
                max_size = lenth;
        }

        return max_size;
    }
};
