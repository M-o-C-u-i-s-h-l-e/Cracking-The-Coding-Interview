// Time Complexity: O(n)
// Space Complexity: O(n)
node *addList(node *n1, node *n2, int rem) {
	if (n1 == NULL && n2 == NULL && rem == 0)
		return NULL;
	node *n = new node();
	int val = rem;
	if (n1 != NULL)
		val += n1->data;
	if (n2 != NULL)
		val += n2->data;
	n->data = val % 10;
	if (n1 != NULL || n2 != NULL) {
		node *temp = addList((n1->next != NULL) ? n1->next : NULL, (n2->next != NULL) ? n2->next : NULL, val / 10);
		n->next = temp;
	}
	return n;
}
