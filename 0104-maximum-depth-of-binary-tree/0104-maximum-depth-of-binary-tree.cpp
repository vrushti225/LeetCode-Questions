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
    int helper(TreeNode* root)
    {
        if(root==nullptr) // reached the end
        return 0;
        
        // add 1 for current + max depth from either side
        return 1+ max(helper(root->left),helper(root->right));
    }
    int maxDepth(TreeNode* root) {
        // using helper function
        return helper(root);
    }
};