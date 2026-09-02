class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.size();
        map < char , int > mp[2];
        map < char , int > ::iterator it;

        if ( len != t.size())
            return false;
        
        
        for( int i = 0; i < len; i++){
            it = mp[0].find( s[i] );

            if ( it == mp[0].end() )
                mp[0].insert( pair <char,int>(s[i],1));
            else 
                it->second++;

        }

        for( int i = 0; i < len; i++){
            it = mp[1].find( t[i] );

            if ( it == mp[1].end() )
                mp[1].insert( pair <char,int>(t[i],1));
            else 
                it->second++;

        }

        return mp[0] == mp[1];

    }
};
