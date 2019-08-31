// Time Complexity: O(n)
// Space Complexity: O(n)
node *partition(node *head, int x) {
	node *beforeStart = NULL, *beforeEnd = NULL;
	node *afterStart = NULL, *afterEnd = NULL;
	while (head != NULL) {
		node *n = head->next;
		head->next = NULL;
		if (head->data < x) {
			if (beforeStart == NULL) {
				beforeStart = head;
				beforeEnd = beforeStart;
			} else {
				beforeStart->next = head;
				beforeEnd = head;
			}
		} else {
			if (afterStart == NULL) {
				afterStart = head;
				afterEnd = afterStart;
			} else {
				afterStart = head;
				afterEnd = head;
			}
		}
		head = n;
	}
	if (beforeStart == NULL)
		return afterStart;
	beforeEnd->next = afterStart;
	return beforeStart;
}





// Another Method
// Time Complexity: O(n)
// Space Complexity: O(n)
node *partition(node *n, int x) {
	node *head = n, *tail = n;
	while (n != NULL) {
		node *next = n->next;
		if (n->data < x) {
			n->next = head;
			head = n;
		} else {
			tail->next = n;
			tail = n;
		}
		n = next;
	}
	tail->next = NULL;
	return head;
}
