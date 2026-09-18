class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        map <int,int> mp;
        int size = stones.size();

        for (auto a : stones)
            mp[a]++;
        while(size>1){
            auto iter = mp.rbegin();
            int big = iter->first;
            iter->second--;

            if(iter->second == 0){
                mp.erase(big);
                iter = mp.rbegin();
            }

            int smaller = iter->first;
            iter->second--;
            if(iter->second == 0)
                mp.erase(smaller);

            if(big != smaller){
                mp[big-smaller]++;
                size++;
            }
            size -= 2;
        }

        return mp.begin()->first;

    }
};
