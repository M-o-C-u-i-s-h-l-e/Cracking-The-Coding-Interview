// Time Complexity: O(n)
// Space Complexity: O(1)
node *findBeginning(node *ls) {
    node *slow = ls;
    node *fast = ls;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    slow = ls;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
