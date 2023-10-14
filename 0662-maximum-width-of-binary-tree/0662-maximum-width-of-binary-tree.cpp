/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        long long int ans = 0;
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int len = q.size();
            long long int maxi = INT_MIN;
            long long int mini = INT_MAX;
            for(int i=0;i<len;i++){
                auto temp = q.front();
                TreeNode*temp1 = temp.first;
                long long int val = temp.second;
                q.pop();
                if(temp1->left){
                    q.push({temp1->left,val*2+1});     
                }
                if(temp1->right){
                    q.push({temp1->right,val*2+2});
                }
                 maxi = max(maxi,val);
                 mini = min(mini,val);
            }
            ans = max(ans,maxi-mini+1);
        }
        return ans;
    }
};