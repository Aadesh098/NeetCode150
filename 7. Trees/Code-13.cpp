// Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index,
                    int i, int j) {
        if (i > j) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }
        index++;
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }