// Time Complexity: O(1)
bool deleteNode(node *n) {
	if (n == NULL || n->next == NULL)
		return false;
	n->data = n->next->data;
	n->next = n->next->next;
	return true;
}
