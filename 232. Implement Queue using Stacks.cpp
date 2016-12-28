class Queue {

    stack<int> s1;
    stack<int> s2;

public:
    // Push element x to the back of queue.
    void push(int x) {

        while(!s1.empty()) {
            int e = s1.top();
            s1.pop();
            s2.push(e);
        }

        s1.push(x);

        while(!s2.empty()) {
            int e = s2.top();
            s2.pop();
            s1.push(e);
        }

    }

    // Removes the element from in front of queue.
    void pop(void) {

        if (!s1.empty())
            s1.pop();

    }

    // Get the front element.
    int peek(void) {

        if (!s1.empty())
            return s1.top();

        return -1;

    }

    // Return whether the queue is empty.
    bool empty(void) {

        return s1.empty() == true;

    }
};
