class Solution {

    bool valid(string &str) {

        stack<char> s;

        for(auto c: str) {
            if (c == '(')
                s.push(c);

            else if(isalpha(c)) {
                // do nothing
            }

            else if (c == ')') {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                    return false;
            }
        }

        if (s.empty())
            return true;
        else
            return false;

    }

    void process(string &s, queue<string> &q, unordered_set<string> &visited) {

        int n = s.length();

        for(int i = 0;i<n;++i) {

            if(s[i]!='(' && s[i]!=')')
                continue;

            string temp = s.substr(0,i) + s.substr(i+1);

            if(visited.find(temp) == visited.end()) {
                q.push(temp);
                visited.insert(temp);
            }
        }

    }


public:
    vector<string> removeInvalidParentheses(string s) {

        queue<string> q;
        vector<string> result;
        unordered_set<string> visited;

        bool ans = false;

        if (valid(s)) {
            result.push_back(s);
            return result;
        }

        q.push(s);
        visited.insert(s);

        while(!q.empty()) {

            int count = q.size();
            while(count--) {
                string top = q.front();
                q.pop();

                if (valid(top)) {
                    ans = true;
                    result.push_back(top);
                }

                process(top, q, visited);

            }

            if (ans)
                break;


        }

         if (result.empty())
            result.push_back("");


        return result;



    }
};
