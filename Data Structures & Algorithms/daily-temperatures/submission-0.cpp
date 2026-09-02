class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len = temp.size();
        stack <int> st;
        vector<int> ans(len );

        if ( len == 1 )
            return { 0 };

        st.push( 0 );

        for( int i = 1;i < len;i++){
            while (!st.empty() and temp[i] > temp [ st.top()] ){
                ans[st.top()] = i - st.top();
                st.pop();
            }


                st.push(i);
        }

        while (!st.empty() ){
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};
