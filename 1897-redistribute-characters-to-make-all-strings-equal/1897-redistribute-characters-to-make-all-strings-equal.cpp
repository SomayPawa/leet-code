class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        int n = words.size();
        for(int i=0;i<n;i++){
            string s1 = words[i];
            int len = s1.size();
            for(int i=0;i<len;i++){
                mp[s1[i]]++;
            }
        }
        vector<int>v1;
        for(auto i:mp){
           if(i.second%n !=0){
               return false;
           }
        }
        return true;
    }
};