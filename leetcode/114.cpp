// Space : O(1)
// Time : O(N)

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
    TreeNode* parentNode; 
    
    void flattenLeft(TreeNode* node) {
        if (node == nullptr) return;
        
        parentNode->left = node;
        parentNode = node;
        
        flattenLeft(node->left);
        flattenLeft(node->right);
    }
    
    void flatten(TreeNode* root) {
        parentNode = root;
        if (root) {
            flattenLeft(root->left);
            flattenLeft(root->right);
        }
        
        while (root != nullptr) {
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
};