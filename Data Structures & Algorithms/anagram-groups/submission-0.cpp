class Solution {
public:
    string calKey(string s){
        string key;
        sort(s.begin(),s.end());

        return s;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string , vector <string> > mp;
         vector<vector<string>> ans;
        string key;

        for (auto str : strs){
            key = calKey(str);
            mp [key] .push_back(str);
        }


        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
