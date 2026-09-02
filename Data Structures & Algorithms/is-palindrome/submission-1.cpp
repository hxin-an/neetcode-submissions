class Solution {
public:
    bool isAlpanumeric ( char ch){
        if (  (ch <= 'z' and ch >= 'a')  or ( ch <= 'Z' and ch >= 'A') or ( ch <= '9' and ch >= '0')  )
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while ( l < r ){
            while ( l<r and ! isAlpanumeric( s[l]) ){
                l++;
            }
            while (l<r and ! isAlpanumeric( s[r]) ){
                r--;
            }
            if( tolower( static_cast<unsigned char>(s[l]) ) !=  tolower ( static_cast<unsigned char>(s[r]) ) )
                return false;

            l++;
            r--;    
        }

        return true;

    }
};


