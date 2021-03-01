// Time : O(N)
// Space : O(N)

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
    unordered_map<int, int> umap;
    
    int pathSum(TreeNode* root, int sum, const int& target) {
        if (root == nullptr) return 0;
        
        int ret = 0;
        int tSum = sum + root->val;
        
        if (tSum == target) ret++;
        ret += umap[tSum - target];
        umap[tSum]++;
        
        ret += pathSum(root->left, tSum, target);
        ret += pathSum(root->right, tSum, target);
        
        umap[tSum]--;
        
        return ret;
    }
    
    int pathSum(TreeNode* root, int sum) {
        return pathSum(root, 0, sum);
    }
};