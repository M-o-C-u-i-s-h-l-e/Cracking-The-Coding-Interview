bool checkBST(TreeNode* root, int min, int max) {
	if (root == NULL)
		return true;
	if ((min != INT_MIN && root->data <= min) || (max != INT_MAX && root->data > max))
		return false;
	if (!checkBST(root->left, min, root->data) || !checkBST(root->right, root->data, max))
		return false;
	return true;
}

bool checkBST(TreeNode* root) {
	return checkBST(root, INT_MIN, INT_MAX);
}
