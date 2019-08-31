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
