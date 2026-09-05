class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1, max_speed = -1;

        for (auto a:piles){
            if ( a > max_speed)
                max_speed = a;
        }

        while ( min_speed <= max_speed){
            int mid = min_speed + (max_speed - min_speed)/2;
            int result = test ( piles, mid, h);

            if (result == 1)
                min_speed = mid + 1;
            else 
                max_speed = mid - 1;
        }

        return min_speed;
    }

    int test( vector <int> & piles , int k, int h){
        long long real = 0;

        for (auto a:piles){
            real = real + a / k;
            if (a % k != 0)
                real++;
        }

        if (real > h)
            return 1;
        else
            return -1;
    }
};
