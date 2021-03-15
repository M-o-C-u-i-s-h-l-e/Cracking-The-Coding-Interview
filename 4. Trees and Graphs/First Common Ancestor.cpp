// With link to parent

TreeNode* getSibling(TreeNode* node) {
	if (node == NULL || node.parent == NULL)
		return NULL;
	TreeNode parent = node->parent;
	return (parent->left == node) ? parent->right : parent->left;
}

bool covers(TreeNode* root, TreeNode* p) {
	if (root == NULL)
		return false;
	if (root == p)
		return true;
	return covers(root->left, p) || covers(root->right, p);
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!covers(root, p) || !covers(root, q)) {
		return NULL;
	} else if (covers(p, q)) {
		return p;
	} else if (covers(q, p)) {
		return q;
	}
	TreeNode* sibling = getSibling(p);
	TreeNode* parent = p->parent;
	while (!covers(sibling, q)) {
		sibling = getSibling(parent);
		parent = parent->parent;
	}
	return parent;
}





// Without link to parent

bool covers(TreeNode* root, TreeNode* p) {
	if (root == NULL)
		return false;
	if (root == p)
		return true;
	return covers(root->left, p) || covers(root->right, p);
}

TreeNode* ancestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || root == p || root == q)
		return root;
	bool pIsOnLeft = covers(root->left, p);
	bool qIsOnLeft = covers(root->left, q);
	if (qIsOnLeft != qIsOnLeft)
		return root;
	TreeNode* childSide = pIsOnLeft ? root->left : root->right;
	return ancestorHelper(childSide, p, q);
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!covers(root, p) || !covers(root, q))
		return NULL;
	return ancestorHelper(root, p, q);
}
