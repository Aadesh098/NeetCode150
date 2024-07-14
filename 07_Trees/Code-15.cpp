// Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

void encode(TreeNode* root, string& out) {
        if (root == NULL) {
            out += "N ";
            return;
        }
        out += to_string(root->val) + " ";
        encode(root->left, out);
        encode(root->right, out);
    }

    TreeNode* decode(const string& data, int& pos) {
        if (pos >= data.size())
            return NULL;
        if (data[pos] == 'N') {
            pos += 2;
            return NULL;
        }
        int space_pos = data.find(' ', pos);
        string value = data.substr(pos, space_pos - pos);
        pos = space_pos + 1;
        TreeNode* root = new TreeNode(stoi(value));
        root->left = decode(data, pos);
        root->right = decode(data, pos);
        return root;
    }
    string serialize(TreeNode* root) {
        string out;
        encode(root, out);
        return out;
    }
    TreeNode* deserialize(const string& data) {
        int pos = 0;
        return decode(data, pos);
    }