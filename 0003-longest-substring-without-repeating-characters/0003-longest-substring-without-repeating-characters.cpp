class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int maxi = 0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]] == 1){
                maxi = max(maxi,j-i+1);
                j++;
            }
            else if(mp[s[j]] > 1){
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};