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
    TreeNode*build(vector<int>&preorder,int pres,int pree,vector<int>&inorder,int ins,int ine,map<int,int>&mp){
        if (pres > pree || ins > ine) return NULL;

        TreeNode*root = new TreeNode(preorder[pres]);
        int prepos = mp[root->val];
        int leftpos = prepos -ins;
        root->left = build(preorder,pres+1,leftpos+pres,inorder,ins,prepos-1,mp);
        root->right = build(preorder,leftpos+pres+1,pree,inorder,prepos+1,ine,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int ins = 0;
        int ine = inorder.size()-1;
        int pres = 0;
        int pree = preorder.size()-1;
        TreeNode*root =  build(preorder,pres,pree,inorder,ins,ine,mp);
        return root;
    }
};