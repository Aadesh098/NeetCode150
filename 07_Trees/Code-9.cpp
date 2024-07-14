// Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

 vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int count = q.size();
            for (int i = count; i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if (i == count) {
                    ans.push_back(node->val);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
        }
        return ans;
    }