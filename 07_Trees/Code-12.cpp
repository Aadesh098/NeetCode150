// Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

void inorder(TreeNode* root, int& k, int& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }