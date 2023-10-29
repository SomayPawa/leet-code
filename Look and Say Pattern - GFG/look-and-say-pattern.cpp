//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
     string solve(string s1){
        int cnt = 1;
        string ans = "";
        for(int i=1;i<s1.size();i++){
            if(s1[i] == s1[i-1]){
                cnt++;
            }
            else{
                ans = ans+to_string(cnt);
                ans = ans+s1[i-1];
                cnt = 1;
            }
        }
         ans+=(cnt+'0');
        ans+=s1[s1.size()-1];
        return ans;
    }
    string lookandsay(int n) {
        // code here
          if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string s1 = "11";
        string s2;
        for(int i = 3;i<=n;i++){
             s2 = solve(s1);
             s1 = s2;
        }
        return s1;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends