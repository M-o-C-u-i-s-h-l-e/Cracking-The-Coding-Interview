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





// Another Method (Follow Up: Part B)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Sum {
public:
	node *n = NULL;
	int rem = 0;
};

int length(node *n) {
	int len = 0;
	while (n != NULL) {
		n = n->next;
		len++;
	}
	return len;
}

node *insertFront(node *n1, int val) {
	node *temp = new node(val);
	temp->next = n1;
	return temp;
}

node *padding(node *n1, int len) {
	for (int i = 0; i < len; i++)
		n1 = insertFront(n1, 0);
	return n1;
}

Sum *addListHelper(node *n1, node *n2) {
	if (n1 == NULL && n2 == NULL) {
		Sum *temp = new Sum();
		return temp;
	}
	Sum *s = addListHelper(n1, n2);
	int val = s->rem + n1->data + n2->data;
	s->n = insertFront(s->n, val % 10);
	s->rem = val % 10;
	return s;
}

node *addList(node *n1, node *n2) {
	int len1 = length(n1);
	int len2 = length(n2);
	if (len1 < len2) {
		n1 = padding(n1, len2 - len1);
	} else {
		n2 = padding(n2, len1 - len2);
	}
	Sum *s = addListHelper(n1, n2);
	if (s->rem != 0)
		s->n = insertFront(s->n, s->rem);
	return s->n;
}
