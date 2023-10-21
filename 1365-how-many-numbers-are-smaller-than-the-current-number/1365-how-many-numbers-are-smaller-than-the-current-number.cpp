class Solution {
public:
    int binary(vector<int>&v,int ele){
        int s = 0;
        int e = v.size()-1;
        int mid;
        int ans;
        while(s<=e){
            mid = (s+e)/2;
            if(v[mid] == ele){
                ans = mid;
                e = mid-1;
            }
            else if(v[mid] > ele){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int x = binary(v,nums[i]);
            ans.push_back(x);
        }
        return ans;
    }
};