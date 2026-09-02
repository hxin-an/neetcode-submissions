class Solution {
public:
    bool isFirst(char s){
        if ( s == '(' or s == '{' or s == '[')
            return true;
        return false ;
    }
    bool isValid(string s) {
        stack <char> st;

        for (char a:s){
            if (isFirst(a) )
                st.push(a);
            else if (st.empty())
                return false;
            else if( a == ')'){
                if (st.top() != '(' )
                    return false;
                st.pop();
            }
            else if( a == '}'){
                if (st.top() != '{' )
                    return false;
                st.pop();
            }
            else if( a == ']'){
                if ( st.top() != '[' ){
                    return false;
                }
                st.pop();
            }
        } 
        if (!st.empty())
            return false;
        return true;
    }
};
