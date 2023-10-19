class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }
        int i = 0;
        int j = 0;
        int cnt = mp.size();
        int minLen = INT_MAX;
        int minStart = 0;
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    cnt--;
                }
            }
            while (cnt == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    minStart = i;
                }
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] > 0) {
                     cnt++;
                     }
                }
                i++;
            }
            j++;
        }
        if(minLen == INT_MAX) {
            return "";
        } else {
            return s.substr(minStart, minLen);
        }
    }
};
