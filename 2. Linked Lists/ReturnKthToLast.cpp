// Time Complexity: O(n)
// Space Complexity: O(n)
node *nthToLast(node *head, int k, int &i) {
	if (head == NULL)
		return NULL;
	node *nd = nthToLast(head->next, k, i);
	i++;
	if (i == k)
		return head;
	return nd;
}

node *nthToLast(node *head, int k) {
	return nthToLast(head, k, 0);
}
