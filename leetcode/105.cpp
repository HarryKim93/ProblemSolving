// Space Complexity : O(N)
// Time Complexity : O(N)

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int idx = -1;

		function<TreeNode*(int, int)> buildTree = [&](int left, int right) -> TreeNode* {
			if (left == right) return nullptr;
			idx++;

			TreeNode* node = new TreeNode(preorder[idx]);
			int i = left;
			while (preorder[idx] != inorder[i]) i++;
			node->left = buildTree(left, i);
			node->right = buildTree(i + 1, right);

			return node;
		};

		return buildTree(0, preorder.size());
	}
};