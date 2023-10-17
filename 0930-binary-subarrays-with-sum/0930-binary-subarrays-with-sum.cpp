class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       /* int sum = 0;
        int j=0;
        int i=0;
        int cnt = 0;
        while(j<=nums.size())
        {
            if(sum<goal)
            {
                sum = sum+nums[j];
                j++;
            }
            else if(sum == goal)
            {
               cnt = cnt+1;
                j++; 
            }
            else if(sum>goal)
            {
                while(sum>=goal && i<j)
                {
                    sum = sum-nums[i];
                    if(sum == goal)
                    {
                        cnt = cnt+1;
                    }
                    i++;
                }
                j++;
            }
        }
        return cnt;*/
        unordered_map<int,int> hmap;
         hmap.insert({0, 1});
        
        int count = 0;
        int currSum = 0;
        for(int i=0; i<nums.size(); ++i){
            currSum += nums.at(i);
            int target = currSum - goal;
            if(hmap.find(target) != hmap.end()){
                count += hmap[target];
            }
            hmap[currSum]++;
        }
        return count;

    }
};