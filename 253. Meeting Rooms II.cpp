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
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        int rooms = 0;

        map<int, int> m;

        for(auto i : intervals) {
            m[i.start]++;
            m[i.end]--;
        }

        int cur = 0;

        for(auto i: m) {
            cur += i.second;
            rooms = max(rooms, cur);
        }

        return rooms;

    }
};
