class MedianFinder {

    priority_queue<int, vector<int> , greater<int>> minheap;
    priority_queue<int, vector<int> , less<int>> maxheap;

public:

    // Adds a number into the data structure.
    void addNum(int num) {

        if (maxheap.empty() || num <= maxheap.top())
            maxheap.push(num);

        else
            minheap.push(num);

        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }


        else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {

       if (minheap.size() == maxheap.size())
            return (0.5*(minheap.top() + maxheap.top()));

        else
            return maxheap.top();


    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
