// Time Complexity: O(n)
// Space Complexity: O(n)
stack<int> values, Min;

int minVal() {
    return (isEmpty(Min) ? INT_MAX : Min.top());
}

void push(int val) {
    if (val <= minVal())
        Min.push(val);
    values.push(val);
}

void pop() {
    if (values.top() == minVal())
        Min.pop();
    values.pop();
}
