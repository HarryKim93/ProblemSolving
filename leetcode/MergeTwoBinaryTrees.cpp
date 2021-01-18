/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Traversal(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return;

        t1->val += t2->val;
        
        if (t1->left == nullptr && t2->left != nullptr) t1->left = new TreeNode();
        if (t2->left != nullptr) Traversal(t1->left, t2->left);
        
        if (t1->right == nullptr && t2->right != nullptr) t1->right = new TreeNode();
        if (t2->right != nullptr) Traversal(t1->right, t2->right);
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* ans = t1;
        
        Traversal(t1, t2);
        return ans;
    }
};