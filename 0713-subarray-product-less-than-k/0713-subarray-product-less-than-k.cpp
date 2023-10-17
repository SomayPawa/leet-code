class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if(k<=1){
            return 0;
        }
        int cnt = 0;
        int i=0;
        int j = 0;
        int len = nums.size();
        int sum = 1;
       // int cnt = 0;
        while(j<len){
            sum = sum*nums[j];
            while(sum>=k){
                sum = sum/nums[i];
                i++;
            }
            cnt = cnt+j-i+1;
            j++;
        }
        return cnt;
    }
};