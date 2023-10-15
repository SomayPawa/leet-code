class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int>ans;
      deque<int>l1;
     
      for(int i=0;i<k;i++){
          while(l1.size()>0 && nums[i]>l1.back()){
             l1.pop_back();
          }
         l1.push_back(nums[i]);
      }
      ans.push_back(l1.front());
       int j = 0;
      for(int i=k;i<nums.size();i++){

            if(nums[j] == l1.front()){
                  l1.pop_front();
                  j++;
            }
            else if(nums[j] != l1.front()){
                j++;
            }
            while(!l1.empty() && nums[i] > l1.back()){
                l1.pop_back();
            }
            l1.push_back(nums[i]);
            ans.push_back(l1.front());
      }  
      return ans;
    }
};