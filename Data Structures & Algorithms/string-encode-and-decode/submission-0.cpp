class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;

        for (const string& str : strs) {
            ans += to_string(str.size()) + '#' + str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // 尋找長度後面的 #
            while (s[j] != '#') {
                j++;
            }

            // s[i...j-1] 是長度
            int length = stoi(s.substr(i, j - i));

            // # 後面固定讀取 length 個字元
            string word = s.substr(j + 1, length);
            ans.push_back(word);

            // 移動到下一個字串的長度欄位
            i = j + 1 + length;
        }

        return ans;
    }
};