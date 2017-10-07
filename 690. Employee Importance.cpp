/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {

        unordered_map<int, pair<int, vector<int>> > m;

        for(auto i: employees) {
            m[i->id] = make_pair(i->importance, i->subordinates);
        }

        if(m.find(id) == m.end())
            return -1;

        int sum = 0;


        queue<int> q;
        q.push(id);

        while(!q.empty()) {

            int i = q.front();
            q.pop();
            sum += m[i].first;
            for(auto it = m[i].second.begin(); it!= m[i].second.end(); it++) {
                q.push(*it);
            }

        }

        return sum;

    }
};
