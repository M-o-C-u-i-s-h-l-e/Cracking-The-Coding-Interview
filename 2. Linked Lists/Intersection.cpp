// Time Complexity: O(n)
// Space Complexity: O(1)
class result {
public:
    node *ls;
    int len;
    result(node *ls, int len) {
        this->ls = ls;
        this->len = len;
    }
};

result *findSizeAndTail(node *ls) {
    if (ls == NULL)
        return NULL;
    int sz = 1;
    while (ls->next != NULL) {
        ls = ls->next;
        sz++;
    }
    return new result(ls, len);
}

node *findKthNode(node *ls, int k) {
    while (k > 0 && ls != NULL) {
        ls = ls->next;
        k--;
    }
    return ls;
}

node *findIntersection(node *ls1, node *ls2) {
    if (ls1 == NULL || ls2 == NULL)
        return NULL;
    result r1 = findSizeAndTail(ls1);
    result r2 = findSizeAndTail(ls2);
    if (r1 != r2)
        return NULL;
    node *short = (r1->len < r2->len) ? ls1 : ls2;
    node *long = (r1->len < r2->len) ? ls2 : ls1;
    long = findKthNode(long, abs(r1->len - r2->len));
    while (long != short) {
        long = long->next;
        short = short->next;
    }
    return long;
}
