// Time Complexity: O(n)
// Space Complexity: O(n)
class FixedMultiStack {
public:
    int noOfStacks = 3;
    int stackCapacity;
    vector<int> values;
    vector<int> size;

    FixedMultiStack(int stackSize) {
        this->stackCapacity = stackSize;
        this->values.resize(stackSize * noOfStacks);
        this->size.resize(noOfStacks);
    }

    bool isFull(int stackNo) {
        return size[stackNo] == stackCapacity;
    }

    bool isEmpty(int stackNo) {
        return size[stackNo] == 0;
    }

    int indexOf(int stackNo) {
        return (stackNo * stackCapacity) + size[stackNo];
    }

    void push(int value, int stackNo) {
        if (isFull(stackNo))
            return;
        values[indexOf(stackNo)] = value;
        size[stackNo]++;
    }

    int pop(int stackNo) {
        if (size[stackNo] == 0)
            return 0;
        size[stackNo]--;
        return values[indexOf(stackNo)];
    }

    int peek(int stackNo) {
        return values[--indexOf(stackNo)];
    }
};
