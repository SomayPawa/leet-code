class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = 0;
        int sum = 0;
        mp[sum] = 1;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            int a1 = sum % k;
            if(a1 < 0 ) a1 += k;
            if(mp.find(a1)!=mp.end()){
                cnt = cnt+mp[a1];
            }
            mp[a1]++;
        }
        return cnt;
    }
};