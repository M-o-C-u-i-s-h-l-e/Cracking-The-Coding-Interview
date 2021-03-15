// String Comparision Approach

void getOrderString(TreeNode* node, string &s) {
	if (node == NULL) {
		s += "X";
		return;
	}
	s += to_string(node->data) + " ";
	getOrderString(node->left, s);
	getOrderString(node->right, s);
}

bool containsTree(TreeNode* t1, TreeNode* t2) {
	string s1 = "", s2 = "";
	getOrderString(t1, s1);
	getOrderString(t2, s2);
	return s1.find(s2) != string::npos;
}





// Alternative Approach

bool matchTree(TreeNode* r1, TreeNode* r2) {
	if (r1 == NULL && r2 == NULL) {
		return true;
	} else if (r1 == NULL || r2 == NULL) {
		return false;
	} else if (r1->data != r2->data) {
		return false;
	}
	return matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right);
}

bool subTree(TreeNode* r1, TreeNode* r2) {
	if (r1 == NULL)
		return false;
	if (r1->data == r2->data && matchTree(r1, r2))
		return true;
	return subTree(r1->left, r2) || subTree(r1->right, r2);
}

bool containsTree(TreeNode* t1, TreeNode* t2) {
	if (t2 == NULL)
		return true;
	return subTree(t1, t2);
}
