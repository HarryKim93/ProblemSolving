// https://leetcode.com/problems/binary-tree-right-side-view/
// O(n)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        function<void(TreeNode*, int)> inorderTraversal = [&](TreeNode* node, int idx) {
            if (node == nullptr) return;
            
            inorderTraversal(node->left, idx + 1);
            if (idx < vec.size()) vec[idx] = move(node->val);
            else {
                while (idx + 1 > vec.size()) vec.emplace_back(node->val);
            }
            inorderTraversal(node->right, idx + 1);
        };
        
        inorderTraversal(root, 0);
        
        return vec;
    }
};