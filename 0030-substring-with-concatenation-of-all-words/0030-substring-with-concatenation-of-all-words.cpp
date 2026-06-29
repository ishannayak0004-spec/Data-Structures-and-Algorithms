class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        unordered_map<string, int> mp;
        for (string &w : words) mp[w]++;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> window;
            int left = i, count = 0;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);

                if (mp.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > mp[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};