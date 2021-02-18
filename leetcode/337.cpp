// TimeComplexity -> O(N)
// MemoryComplexity -> O(N)

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int rob(TreeNode* root, TreeNode* cache0, TreeNode* cache1, bool state) {
//         if (root == nullptr) return 0;
        
//         if (state) {
//             if (cache1->val != 0) return cache1->val;
//             cache1->val = rob(root->left, cache0->left, cache1->left, false) + rob(root->right, cache0->right, cache1->right, false) + root->val;
            
//             return cache1->val;
//         } else {
//             if (cache0->val != 0) return cache0->val;
//             cache0->val = max<int>(rob(root->left, cache0->left, cache1->left, false), rob(root->left, cache0->left, cache1->left, true)) + 
//                                 max<int>(rob(root->right, cache0->right, cache1->right, false), rob(root->right, cache0->right, cache1->right, true));
        
//             return cache0->val;
//         }
//     }
    
//     void cacheMake(TreeNode* root, TreeNode* cacheRoot0, TreeNode* cacheRoot1) {
//         if (root == nullptr) return ;
        
//         if (root->left) {
//             cacheRoot0->left = new TreeNode();
//             cacheRoot1->left = new TreeNode();
//         }
//         cacheMake(root->left, cacheRoot0->left, cacheRoot1->left);
        
//         if (root->right) {
//             cacheRoot0->right = new TreeNode();
//             cacheRoot1->right = new TreeNode();
//         }
//         cacheMake(root->right, cacheRoot0->right, cacheRoot1->right);
//     }
    
//     int rob(TreeNode* root) {
//         TreeNode* cacheRoot[2];
//         cacheRoot[0] = new TreeNode();
//         cacheRoot[1] = new TreeNode();
        
//         cacheMake(root, cacheRoot[0], cacheRoot[1]);
        
//         return max<int>(rob(root, cacheRoot[0], cacheRoot[1], false), rob(root, cacheRoot[0], cacheRoot[1], true));
//     }
// };

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
    unordered_map<TreeNode*, int> umap[2];
    
    int rob(TreeNode* root, bool state) {
        if (root == nullptr) return 0;
        
        if (!umap[state].count(root)) { 
            if (state) {
                umap[state][root] = rob(root->left, false) + rob(root->right, false) + root->val;;
            } else {
                umap[state][root] = max<int>(rob(root->left, false), rob(root->left, true)) + 
                                    max<int>(rob(root->right, false), rob(root->right, true));
            }
        }
        
        return umap[state][root];
    }

    
    int rob(TreeNode* root) {
        return max<int>(rob(root, false), rob(root, true));
    }
};