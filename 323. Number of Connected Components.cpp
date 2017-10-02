class Solution {

    void dfs(int key, unordered_map<int, vector<int> > &relation, unordered_set<int> &visited) {
        visited.insert(key);
        for(auto it = relation[key].begin(); it!= relation[key].end(); it++) {
            if(visited.find(*it) == visited.end())
                dfs(*it, relation, visited);
        }
    }

public:
    int countComponents(int n, vector<pair<int, int>>& edges) {

        unordered_map<int, vector<int> > relation;
        unordered_set<int> visited;

        for(auto i: edges) {
            relation[i.first].push_back(i.second);
            relation[i.second].push_back(i.first);
        }

        int count = 0;

        for(int i = 0;i<n;i++) {
            if(visited.find(i) == visited.end()) {
                count++;
                dfs(i, relation, visited);
            }
        }

        return count;


    }
};
