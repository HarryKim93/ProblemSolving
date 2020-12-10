// https://leetcode.com/problems/path-sum/
// O(n)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        function<bool(int&, TreeNode*)> func = [&](int& currentSum, TreeNode* node){
            if (node == nullptr) return false;
            currentSum += node->val;
            
            if (node->left == nullptr && node->right == nullptr) {
                currentSum -= node->val;
                return sum == currentSum + node->val;    
            } else {
                if (func(currentSum, node->left)) {
                    currentSum -= node->val;
                    return true;
                }
                else if (func(currentSum, node->right)) {
                    currentSum -= node->val;
                    return true;  
                }
                currentSum -= node->val;
                return false;
            }
        };
        
        int _sum = 0;
        return root == nullptr ? false : func(_sum, root);
    }
};