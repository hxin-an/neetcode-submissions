class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> mp;
        int tmp = calSum(n);
        while ( mp.find(tmp) == mp.end() ){
            if ( tmp == 1)
                return true;
            mp.insert(tmp);
            tmp = calSum(tmp);
        }

        return false;

    }
    int calSum (int n){
        int sum = 0;
        sum +=  pow(n % 10,2);
         
        do{
            n /= 10;
            sum +=  pow(n % 10,2);
        }while ( n / 10 > 0);

        return sum;
    }
};
