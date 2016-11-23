class Solution {

    map<string, multiset<string> > airport;
    vector<string> result;

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {


        if (tickets.size() < 1)
            return result;

        for(int i = 0;i<tickets.size(); ++i){

            airport[tickets[i].first].insert(tickets[i].second);

        }

        visit("JFK");
        
        reverse(result.begin(),result.end());

        return result;

    }

    void visit(string dest) {

        while(airport[dest].size()) {
            auto it = airport[dest].begin();
            airport[dest].erase(it);
            visit(*it);
        }

        result.push_back(dest);

    }


};
