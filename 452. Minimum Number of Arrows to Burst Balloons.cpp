class Solution {
public:


    struct mycomp {
        bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) {
            return p1.first > p2.first;
        }
    };

    int findMinArrowShots(vector<pair<int, int>>& points) {

        int n = points.size();

        if(!n)
            return 0;
        if(n==1)
            return 1;

        vector<pair<int,int> > res;
        priority_queue<pair<int,int>, vector<pair<int,int> > ,mycomp > pq;

        for(auto i : points) {
            pq.push(i);
        }

        while(pq.size() > 1) {

            pair<int,int> top;
            pair<int,int> sec;



            top = pq.top();
            pq.pop();

            sec = pq.top();
            pq.pop();

            // cout << top.first <<" " << top.second << endl;
            // cout << sec.first <<" " << sec.second << endl;

            if (top.first <=sec.first && top.second >=sec.second)
                pq.push({sec.first, sec.second});

            else if(top.first <=sec.first && top.second <= sec.second && top.second>=sec.first)
                pq.push({sec.first, top.second});

            else if(top.second < sec.first) {
                res.push_back(top);
                pq.push(sec);
            }

        }



        if(pq.size() == 1)
            res.push_back(pq.top());


        return res.size();


    }
};
