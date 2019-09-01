// Time Complexity: O(n)
// Space Complexity: O(n)
bool isEqual(node *n1, node *n2) {
	while (n1 != NULL && n2 != NULL) {
		if (n1->data != n2->data)
			return false;
		n1 = n1->next;
		n2 = n2->next;
	}
	return (n1 == NULL && n2 == NULL);
}

node *reverse(node *n) {
	node *head = NULL;
	while (n != NULL) {
		node *temp = new node(n->data);
		temp->next = head;
		head = temp;
		n = n->next;
	}
	return head;
}

bool palindrome(node *n) {
	node *rev = reverse(n);
	return isEqual(n, rev);
}
