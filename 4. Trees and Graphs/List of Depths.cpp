vector<vector<TreeNode*>> createLevelList(TreeNode* root) {
	vector<vector<TreeNode*>> res;
	vector<TreeNode*> cur;
	if (root != NULL)
		cur.push_back(root);
	while (cur.size()) {
		res.push_back(cur);
		vector<TreeNode*> parents = cur;
		cur.clear();
		for (TreeNode* parent: parents) {
			if (parent->left != NULL)
				cur.push_back(parent->left);
			if (parent->right != NULL)
				cur.push_back(parent->right);
		}
	}
	return res;
}
