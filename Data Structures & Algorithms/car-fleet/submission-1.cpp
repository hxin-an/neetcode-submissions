class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map <int, int > mp;
        int fleet = 1;
        float prev_time;

        for(int i = 0;i < position.size();i++){
            mp[ -position[i] ] = speed[i]; 
        }

        prev_time = 1.0 * (target + mp.begin()->first ) /mp.begin()->second;
        mp.erase(mp.begin());

        for( auto a : mp){
            float time =  1.0 * (target + a.first ) / a.second ;

            if (time <= prev_time){
                time = prev_time;
            }else{
                fleet++;
            }
            prev_time = time;
        }

        return fleet;

    }
};


// 根據位置排序
// 從離 目標進的開始計算
// 到終點所花的時間比前一台車還短的話 fleet 加
// 到終點所花的時間比後一台車還短的話 fleet 加
