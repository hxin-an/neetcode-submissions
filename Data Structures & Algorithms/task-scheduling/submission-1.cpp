class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map <char,int> mp;
        priority_queue < int >  pq;
        int ideal = 0,len = tasks.size(),tmp ;

        for (auto a : tasks){
            mp[a]++;
        }
        
        for( auto a: mp){
            pq.push( a.second );
        }

        tmp = pq.top();

        while (!pq.empty() and pq.top() == tmp){
            if (ideal == 0){
                ideal = (n + 1) * ( pq.top() - 1);
            }
            ideal += 1;
            pq.pop();
        }
      
        return max( len, ideal);
    }
};

// 計算 骨架長度和實際長度