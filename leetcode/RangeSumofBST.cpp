// https://leetcode.com/problems/range-sum-of-bst/submissions/
// O(N)

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if (root == nullptr) return 0;
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
        if (low <= root->val && root->val <= high) sum += root->val;
        return sum;
    }
};