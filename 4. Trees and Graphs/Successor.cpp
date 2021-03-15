TreeNode* leftMostChild(TreeNode* root) {
	if (root == NULL)
		return NULL;
	while (root->left != NULL)
		root = root->left;
	return root;
}

TreeNode* inorderSucc(TreeNode* root) {
	if (root == NULL)
		return NULL;
	if (root->right != NULL) {
		return leftMostChild(root->right);
	} else {
		TreeNode* cur = root;
		TreeNode* par = cur->parent;
		while (par != NULL && par->left != cur) {
			cur = par;
			par = par->parent;
		}
		return par;
	}
}
