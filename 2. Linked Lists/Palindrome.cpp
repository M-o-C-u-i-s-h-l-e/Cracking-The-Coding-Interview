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





// Another Method
// Time Complexity: O(n)
// Space Complexity: O(n)
bool palindrome(node *n) {
	stack<int> st;
	node *slow = n, *fast = n;
	while (fast != NULL && fast->next != NULL) {
		st.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != NULL)
		slow = slow->next;
	while (slow != NULL) {
		if (st.top() != slow->data)
			return false;
		st.pop();
		slow = slow->next;
	}
	return true;
}





// Another Method
// Time Complexity: O(n)
// Space Complexity: O(n)
class Result {
public:
	node *n = NULL;
	bool result = true;
	Result(node *n, bool result) {
		this->n = n;
		this->result = result;
	}
};

int length(node *n) {
	int len = 0;
	while (n != NULL) {
		n = n->next;
		len++;
	}
	return len;
}

Result *isPalindrome(node *n, int len) {
	if (n == NULL || len <= 0)
		return new Result(n, true);
	if (len == 1)
		return new Result(n->next, true);
	Result *res = isPalindrome(n->next, len - 2);
	if (!res.result || res.node == NULL)
		return res;
	res->result = (n->data == res->n->data);
	res->n = res->n->next;
	return res;
}

bool palindrome(node *n) {
	int len = length(n);
	Result *res = isPalindrome(n, len);
	return res.result;
}
