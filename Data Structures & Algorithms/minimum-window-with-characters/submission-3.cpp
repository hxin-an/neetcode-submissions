class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int ans_l = 0;
        int ans_size = INT_MAX;

        vector<int> s_window_mp(52,0), t_mp(52,0);

        for(auto a:t)
            t_mp[toKey(a)]++;
        
        for(int i = 0; i < s.size();i++){
            s_window_mp[toKey(s[i])]++;

            while ( isSubstring(s_window_mp,t_mp) ){

                if(i - l + 1 < ans_size){
                    ans_l = l;
                    ans_size = i - l + 1;
                }

                s_window_mp[toKey(s[l])]--;
                l++;
            }
        }

        if(ans_size == INT_MAX)
            return "";

        return s.substr(ans_l, ans_size);
    }

    bool isSubstring(vector<int>& s_window_mp, vector<int>& t_mp){
        for(int i = 0; i < s_window_mp.size();i++){
            if(t_mp[i] > s_window_mp[i])
                return false;
        }
        return true;
    }

    int toKey(char s){
        if(s >= 'a' && s <= 'z')
            return s-'a';
        else
            return s-'A'+26;
    }
};