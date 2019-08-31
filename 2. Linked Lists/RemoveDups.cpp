// Time Complexity: O(n)
// Space Complexity: O(n)
void deleteDups(node *head) {
	set<int> s;
	node *prev = NULL;
	while (head != NULL) {
		if (s.count(head.data)) {
			prev.next = head.next;
		} else {
			s.insert(head.data);
			prev = head;
		}
		head = head.next;
	}
}





// Another Method
// Time Complextiy: O(n ^ 2)
// Space Complextiy: O(1)
void deleteDups(node *head) {
	while (head != NULL) {
		node *prev = head;
		while (prev->next != NULL) {
			if (prev->next->data == head->data) {
				prev->next = prev->next->next;
			} else {
				prev = prev->next;
			}
		}
		head = head->next;
	}
}
