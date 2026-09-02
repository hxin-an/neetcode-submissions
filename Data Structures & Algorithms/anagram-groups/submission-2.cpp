class Solution {
public:
    string calKey(const string& s) {
        array<int, 26> count{};

        for (char c : s) {
            count[c - 'a']++;
        }

        string key;
        for (int i = 0; i < 26; i++) {
            key += '#';
            key += to_string(count[i]);
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const auto& str : strs) {
            string key = calKey(str);
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& [key, group] : mp) {
            ans.push_back(group);
        }

        return ans;
    }
};