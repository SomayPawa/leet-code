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
    int countNodes(TreeNode* root) {
        queue<TreeNode*>q;
        int count = 0;
        if(root == NULL){
            return count;
        }
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int>ans;
            for(int i=0;i<len;i++){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                ans.push_back(temp->val);
            }
            count = count+ans.size();
        }
        return count;
    }
};