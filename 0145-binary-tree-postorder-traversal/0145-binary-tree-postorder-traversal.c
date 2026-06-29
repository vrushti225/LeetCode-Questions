int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode* stack1[100];
    struct TreeNode* stack2[100];
    int top1 = -1, top2 = -1, index = 0;

    if (root) stack1[++top1] = root;

    while (top1 >= 0) {
        struct TreeNode* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }

    while (top2 >= 0) {
        result[index++] = stack2[top2--]->val;
    }

    *returnSize = index;
    return result;
}