class MyCircularDeque {
    deque<int> dq;
    int k;
public:
    MyCircularDeque(int k) {
        this->k = k;
    }

    bool insertFront(int value) {
        if (!isFull()) {
            dq.push_front(value);
            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        if (!isFull()) {
            dq.push_back(value);
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        dq.pop_front();
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        dq.pop_back();
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : dq.front();
    }

    int getRear() {
        return isEmpty() ? -1 : dq.back();
    }

    bool isEmpty() {
        return dq.empty();
    }

    bool isFull() {
        return dq.size() == k;
    }
};
