class MinStack {
private:
    vector <int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[ st.size() - 1];
    }
    
    int getMin() {
        int imin = INT_MAX;
        for ( auto a : st){
            if ( a < imin)
                imin = a;
        }
        return imin;
    }
};
