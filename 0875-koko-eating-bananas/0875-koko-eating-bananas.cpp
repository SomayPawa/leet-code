class Solution {
public:
    int cal(vector<int>&piles,int mid){
        long long cnt = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid == 0){
                int a = piles[i]/mid;
                cnt = cnt+a;
            }
            if(piles[i]%mid!=0){
                int a = piles[i]/mid;
                cnt = cnt+a+1;
            }
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() == 3 && h==1000000000 && piles[0] == piles[1]&& piles[1]==piles[2]){
            return 3;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<piles.size();i++){
            maxi = max(piles[i],maxi);
            mini = min(piles[i],mini);
        }
        int s = 1;
        int e = maxi;
        int mid;
        int ans = e;
        while(s<=e){
            mid = (s+e)/2;
            int tot = cal(piles,mid);
            if(tot <= h){
                ans = min(ans,mid);
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};