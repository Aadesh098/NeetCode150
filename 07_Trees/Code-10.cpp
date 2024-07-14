// Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

void dfs(TreeNode* root, int maxSoFar, int& result) {
        if (root == NULL) {
            return;
        }
        if (root->val >= maxSoFar) {
            result++;
        }
        dfs(root->left, max(maxSoFar, root->val), result);
        dfs(root->right, max(maxSoFar, root->val), result);
    }
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }