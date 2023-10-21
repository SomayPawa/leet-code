class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid;
        int mini = INT_MAX;
        while(s<=e){
            mid = (s+e)/2;
            if(nums[s] < nums[mid]){
                if(nums[mid] > nums[e]){
                    s = mid+1;
                    mini = min(nums[mid],mini);
                }
                else{
                    mini = min(mini,nums[mid]);
                    e = mid-1;
                }
            }
            else{
                if(nums[mid]<nums[s]){
                    e = mid-1;
                    mini = min(nums[mid],mini);
                 
                }
                else{
                    s = mid+1;
                    mini = min(nums[mid],mini);
                }
            }
        }
        return mini;
    }
};