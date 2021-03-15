int checkHeight(TreeNode* root) {
	if (root == NULL)
		return -1;
	int leftHt = checkHeight(root->left);
	if (leftHt == INT_MAX)
		return INT_MAX;
	int rightHt = checkHeight(root->right);
	if (rightHt == INT_MAX)
		return INT_MAX;
	int htDiff = abs(leftHt - rightHt);
	if (htDiff > 1) {
		return INT_MAX;
	} else {
		return max(leftHt, rightHt) + 1;
	}
}

bool isBalanced(TreeNode* root) {
	return checkHeight(root) != INT_MAX;
}
