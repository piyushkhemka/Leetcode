class MinStack {

    vector<pair<int,int> >s;
    int mina;

public:
    /** initialize your data structure here. */
    MinStack() {
        mina = INT_MAX;
    }

    void push(int x) {

        mina = min(mina, x);
        s.push_back({ x, mina });

    }

    void pop() {
        if (!s.empty())
            s.pop_back();

        if (s.empty())
            mina = INT_MAX;
        else
            mina = getMin();
    }

    int top() {

        return s.back().first;
    }

    int getMin() {

        return s.back().second;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
