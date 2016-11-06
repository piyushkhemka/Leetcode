/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {

    struct mycomp {
        bool operator() (Interval &p1, Interval &p2) {
            return p1.start > p2.start;
        }
    };

public:
    vector<Interval> merge(vector<Interval>& intervals) {

         int n = intervals.size();
         vector<Interval> res;

        if(!n)
            return res;


        priority_queue<Interval, vector<Interval> ,mycomp > pq;

        for(auto i : intervals) {
            pq.push(i);
        }

        while(pq.size() > 1) {

            Interval top;
            Interval sec;

            top = pq.top();
            pq.pop();

            sec = pq.top();
            pq.pop();

            if (top.start <=sec.start && top.end >=sec.end)
                pq.push({top.start, top.end});


            else if(top.start <=sec.start && top.end <= sec.end && top.end>=sec.start)
                pq.push({top.start, sec.end});

            else if(top.end < sec.start) {
                res.push_back(top);
                pq.push(sec);
            }

        }

        if(pq.size() == 1)
            res.push_back(pq.top());

        return res;

    }
};
