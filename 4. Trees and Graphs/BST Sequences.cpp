void weavLists(vector<int> &first, vector<int> &second, vector<vector<int>> &res, vector<int> &prefix) {
	if (first.size() == 0 || second.size() == 0) {
		vector<int> temp(prefix.begin(), prefix.end());
		temp.insert(temp.end(), first.begin(), first.end());
		temp.insert(temp.end(), second.begin(), second.end());
		res.push_back(temp);
		return;
	}

	int firstHead = first[0];
	first.erase(first.begin());
	prefix.push_back(firstHead);
	weavLists(first, second, weaved, prefix);
	prefix.pop_back();
	first.insert(first.begin(), firstHead);

	int secondHead = second[0];
	second.erase(second.begin());
	prefix.push_back(secondHead);
	weavLists(first, second, weaved, prefix);
	prefix.pop_back();
	second.insert(second.begin(), secondHead);
}

vector<vector<int>> allSeq(TreeNode* node) {
	vector<vector<int>> res;
	if (node == NULL)
		return res;

	vector<int> prefix;
	prefix.push_back(node->data);
	vector<vector<int>> leftSeq = allSeq(node->left);
	vector<vector<int>> rightSeq = allSeq(node->right);
	for (vector<int> left: leftSeq) {
		for (vector<int> right: rightSeq) {
			vector<vector<int>> weaved;
			weavLists(left, right, weaved, prefix);
			res.insert(res.end(), weaved.begin(), weaved.end());
		}
	}
	return res;
}
