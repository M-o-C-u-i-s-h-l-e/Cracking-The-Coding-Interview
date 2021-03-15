TreeNode* createMinBST(vector<int> v, int st, int ed) {
	if (ed < st)
		return NULL;
	int mid = (st + ed) >> 1;
	TreeNode* cur = new TreeNode(v[mid]);
	cur->left = createMinBST(v, st, mid-1);
	cur->right = createMinBST(v, mid+1, ed);
	return cur;
}

TreeNode* createMinBST(vector<int> v) {
	return createMinBST(v, 0, v.size()-1);
}
