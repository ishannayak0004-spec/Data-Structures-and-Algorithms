class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int idx, string &temp) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char c : letters) {
            temp.push_back(c);
            solve(digits, idx + 1, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string temp;
        solve(digits, 0, temp);
        return ans;
    }
};