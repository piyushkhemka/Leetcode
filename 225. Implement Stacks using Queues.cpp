class Stack {

    queue<int> q1;
    queue<int> q2;

public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {

        while(q1.size() > 1) {
            int e = q1.front();
            q1.pop();
            q2.push(e);
        }

        if (!q1.empty())
            q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Get the top element.
    int top() {
        int e;
         while(!q1.empty()) {
            e = q1.front();
            q1.pop();
            q2.push(e);
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return e;
    }

    // Return whether the stack is empty.
    bool empty() {

        return q1.empty() && q2.empty();

    }
};


-------

// Better solution
//
// 1 queue solution with O(n) for push and O(1) for every other operation

class Stack {
    queue<int> q;

public:
    // Push element x onto stack.
    void push(int x) {

        q.push(x);
        int s = q.size();
        while(s > 1) {
            int e =  q.front();
            q.pop();
            q.push(e);
            s--;
        }

    }

    // Removes the element on top of the stack.
    void pop() {

        if (!q.empty())
            q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
