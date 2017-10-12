class Solution {

    struct Node {
        int num;
        int index;
        int array;
        Node(int a, int b, int c) : num(a), index(b), array(c) {}
    };

    struct mycomp {
        bool operator() (Node* &n1, Node* &n2) {
            return n1->num > n2->num;
        }
    };


public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<Node*, vector<Node*> , mycomp> pq;
        int maxsofar = INT_MIN;
        int rangesize = INT_MAX;
        vector<int> range (2, -1);

        for(int i = 0;i<nums.size();i++) {

            if(!nums[i].empty()) {
                pq.push(new Node(nums[i][0], 0, i));
                maxsofar = max(maxsofar, nums[i][0]);
            }
            else
                return range;
        }

        rangesize = maxsofar - pq.top()->num;
        range[0] = pq.top()->num;
        range[1] = maxsofar;

        while(!pq.empty()) {

            Node* topmost = pq.top();
            int number = pq.top()->num;
            int index = pq.top()->index;
            int array = pq.top()->array;

            pq.pop();

            if(index+1 >= nums[array].size())
                break;

            if(index < nums[array].size()) {
                pq.push(new Node(nums[array][index+1], index+1, array));
                maxsofar = max(maxsofar, nums[array][index+1]);

                if((maxsofar - pq.top()->num < range[1] - range[0]) ||
                   (( range[0] > pq.top()->num) && (maxsofar - pq.top()->num == range[1] - range[0]))) {

                    range[0] = pq.top()->num;
                    range[1] = maxsofar;

                    rangesize = range[1] - range[0];
                }
            }
            else {
                break;
            }
        }

        return range;

    }
};
