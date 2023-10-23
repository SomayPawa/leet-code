class Solution {
public:
    int func(vector<int>& nums,int n,int mid){
        int val = 0;
        for(int i=0;i<n;i++){
            if(nums[i] % mid == 0){
                val = val+(nums[i]/mid);
            }
            else{
                val = val+(nums[i]/mid)+1;
            }
        }
        return val;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = INT_MIN;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            e = max(e,nums[i]);
        }
        int mid = (s+e)/2;
        while(s<=e){
            int a = func(nums,n,mid);
            if(a<=threshold){
                ans = min(ans,mid);
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = (s+e)/2;
        }
        return ans;
    }
};