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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==NULL) return answer;
        queue<TreeNode*> queuenode;
        queuenode.push(root);
        bool flag=true;
        while(!queuenode.empty())
        {
            int size=queuenode.size();
            vector<int> row(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=queuenode.front();
                queuenode.pop();

                int index=flag?i:(size-i-1);
                row[index]=node->val;
                if(node->left!=NULL) 
                queuenode.push(node->left);
                if(node->right!=NULL)
                queuenode.push(node->right);
            }
            flag=!flag;
            answer.push_back(row);
        }
        return answer;
    }
};