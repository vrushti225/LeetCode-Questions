void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    inorder(root->left, result, index);
    result[(*index)++] = root->val;
    inorder(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // max 100 nodes
    *returnSize = 0;
    inorder(root, result, returnSize);
    return result;
}