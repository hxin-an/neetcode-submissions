class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> mp(26,0);
        int len = s1.size();

        for( auto ch : s1){
            mp[ch-'a']++;
        }

        
        for(int i = 0; i < s2.size();i++ ){
            if( i >= len)
               mp[s2[i-len] - 'a']++;
            mp[s2[i] - 'a']--;
            
            if (mp_empty(mp))
                return true;
            
        }
        

        return false;
    }

    bool mp_empty( vector<int> & mp){
        for ( auto a: mp){
            if(a != 0)
                return false;
        }

        return true;        
    }
};

// 使用 vector map  紀錄 s1 的頻率
// 用 sliding window 滑動比較窗口內數量
// 有對上 return 沒對上 