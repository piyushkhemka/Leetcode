class Solution {
public:
    bool isValid(string s) {
        stack<char> q;

        for(int i = 0;i<s.length(); ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                q.push(s[i]);

          else if(s[i] == ')') {
                if(q.empty() || q.top() != '(')
                    return false;

                    q.pop();
            }
           else if(s[i] == '}') {
                if(q.empty() || q.top() != '{')
                    return false;

                    q.pop();
            }
          else  if(s[i] == ']') {
                if(q.empty() || q.top() != '[')
                    return false;

                    q.pop();
            }
        }

        if(!q.empty())
            return false;

        return true;

    }
};
