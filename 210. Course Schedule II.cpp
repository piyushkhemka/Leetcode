class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<int> count (numCourses, 0);
        map<int,vector<int> > nodes;
        vector<int> result;

        for(auto it:prerequisites) {
            nodes[it.second].push_back(it.first);
            count[it.first]++;
        }

        queue<int> q;

        for(int i = 0; i< count.size(); ++i){
            if (count[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {

            int top = q.front();
            q.pop();

            result.push_back(top);

            for(auto it = nodes[top].begin(); it!=nodes[top].end(); ++it) {
                count[*it]--;

                if (!count[*it])
                    q.push(*it);

            }

            if(nodes.find(top)!=nodes.end())
                nodes.erase(top);

        }

        if (nodes.empty())
            return result;
        else
            return vector<int> ();



    }
};
