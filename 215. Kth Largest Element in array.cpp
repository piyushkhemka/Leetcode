class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int> > pq;

        int i = 0;

        while(pq.size() < k)
            pq.push(nums[i++]);

        while(i < nums.size()) {
            if (nums[i] >  pq.top()) {
                pq.pop(); // check for underflow if k could be less than nums len or greater
                pq.push(nums[i]);
            }
            i++;
        }

        return pq.top();


    }
};

-------------------

// Bad solution :  This is OlogN and not OlogK because pq is of size n and not k

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int> > pq;


        for(auto i : nums) {
            pq.push(i);
        }

        while(pq.size() > k) {
            pq.pop();
        }

        return pq.top();


    }
};
