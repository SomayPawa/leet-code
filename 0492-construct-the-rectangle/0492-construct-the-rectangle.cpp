class Solution {
public:
    vector<int> constructRectangle(int area) {
        int a = sqrt(area);
        vector<int>v;
        int ans1,ans2;
        for(int i=a;i>0;i--){
            if(area % i == 0){
                ans1 = area/i;
                ans2 = i;
                break;
            }
        }
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};