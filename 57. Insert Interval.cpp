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

      bool operator() (Interval &i, Interval &j) {
          return i.start > j.start;
      }

    };

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

        vector<Interval> result;
        priority_queue<Interval, vector<Interval>, mycomp> pq;

        for(auto i: intervals)
            pq.push(i);
            
        pq.push(newInterval);

        while(pq.size() > 1) {

            Interval top = pq.top();
            pq.pop();

            Interval sec = pq.top();
            pq.pop();

            if (top.end < sec.start) {
                result.push_back(top);
                pq.push(sec);
            }

            else if (top.end >= sec.end)
                pq.push(top);

            else if (top.start <= sec.start && top.end >= sec.start && top.end <= sec.end)
                pq.push({top.start, sec.end});

        }

        if(!pq.empty())
            result.push_back(pq.top());

        return result;



    }
};
