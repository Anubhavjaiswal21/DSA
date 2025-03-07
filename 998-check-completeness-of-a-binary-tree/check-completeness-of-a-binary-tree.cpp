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
    int count_nodes(TreeNode* root)
    {
        if(!root) return 0;
        int l=count_nodes(root->left);
        int r=count_nodes(root->right);
        return l+r+1;
    }
    bool check(TreeNode* root, int ind,int n)
    {
        if(!root) return 1;
        if(ind>=n) return 0;

        bool l=check(root->left,2*ind+1,n);
        bool r=check(root->right,2*ind+2,n);
        return l and r;
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root) return 1;
        int n=count_nodes(root);
        return check(root,0,n);
    }
};