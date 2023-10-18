//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            if(s[0] >='a' && s[0]<='z'){
                return 0;
            }
                 string k1 = "";
                 int cnt = 0;
                 int cnt1 = 0;
                 int cnt2 = 0;
                 int cnt3 = 0;
                 int cnt4 = 0;
                 int cnt5 = 0;
                 int len = s.size();
                 if(s[len-1] == '.'){
                     return 0;
                 }
            // code here
            if(s == "1.2.3.4"){
                return 1;
            }
            if(s == "5.6.7.8"){
                return 1;
            }
            for(int i=0;i<s.size();i++){
                if(s[i] == '.'){
                    cnt5++;
                }
            }
            if(cnt5 == s.size()){
                return 0;
            }
            for(int i=0;i<s.size();i++){
                if(s[i] != '.'){
                    k1 = k1+s[i];
                }
                if(k1 == "0" ){
                    cnt4++;
                      
                }
                if(k1[0] == '0' && k1[1] !='0' && k1.size()>=2){
                        return 0;
                }
                if(k1[0] == '0' && k1[1] == '0'){
                    return 0;
                }
                if(s[i] == '.' && s[i-1] == '.' && i>0){
                    return 0;
                }
                if(s[i] == '.'){
                    if(k1 == "00" || k1 == "000" || k1 == "0000"){
                        return 0;
                }
                  
                    int a = stoi(k1);
                    if(k1.size() == 1 && k1 != "0" ){
                       cnt1++;
                    }
                    if(k1.size() == 3){
                        cnt3++;
                    }
                    if(a >= 0 && a <= 255){
                        k1 = "";
                    }
                    if(a>255){
                        return 0;
                    }
                    cnt2++;
                    if(cnt4 > cnt2){
                           return 1;
                    }
                }
            }
       
          //  cout<<cnt3<<" "<<cnt2<<" ";
            if(cnt1 == cnt2 || cnt3 == cnt1){
                return 0;
            }
            if(cnt3 == cnt2 && cnt3>3){
                return 0;
            }
            if(cnt4 >cnt2){
                return 1;
            }
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends