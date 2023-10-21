class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        int third = INT_MAX;
        int i=0;
        while(i<nums.size()){
            if(first>=nums[i]){
                first = nums[i];
            }
            if(second>=nums[i] && nums[i]>first){
                second = nums[i];
            }
            if(third >= nums[i] && nums[i]>second){
                third = nums[i];
                return true;
            }
            i++;
        }
        return false;
    }
};