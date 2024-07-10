// Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/description/

int dfs(TreeNode* root, int& ans) {
        if (root == NULL) {
            return 0;
        }
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }