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





// Another Method
// Time Complexity: O(n)
// Space Complexity: O(1)
node *nthToLast(node *head, int k) {
	node *p1 = head, *p2 = head;
	for (int i = 0; i < k; i++) {
		if (p1 == NULL)
			return NULL;
		p1 = p1->next;
	}
	while (p1 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}
