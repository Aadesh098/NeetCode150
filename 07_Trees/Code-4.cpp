// Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

bool dfs(TreeNode* root, int& height) {
        if (root == NULL) {
            height = -1;
            return true;
        }
        int left = 0;
        int right = 0;
        if (!dfs(root->left, left) || !dfs(root->right, right)) {
            return false;
        }
        if (abs(left - right) > 1) {
            return false;
        }
        height = 1 + max(left, right);
        return true;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }