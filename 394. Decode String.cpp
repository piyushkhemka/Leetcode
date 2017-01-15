class Solution {
public:
    string decodeString(string s) {

        stack<string> st;
        stack<int> num;
        int n = 0;
        string result = "";

        for(int i = 0; i<s.length() ; ++i) {

            if (isdigit(s[i])) {
                n = n*10 + (int)s[i] - '0';
            }

            else if (isalpha(s[i])) {
                result.push_back(s[i]);
            }

            else if (s[i] == '[') {

                num.push(n);
                st.push(result);
                result = "";
                n = 0;

            }

            else if (s[i] == ']') {

                string here = result;

                int rep = num.top();
                num.pop();
                rep--;
                while(rep--) {
                    result += here;
                }

                result = st.top() + result;
                st.pop();
            }
        }

        return result;


    }
};



----------------------
// Recursive Solution

class Solution {


    string helper(string s, int &i) {

        if (s.empty())
            return s;

        string res = "";
      //  cout << s.substr(i) << endl;

        while(i < s.length() && s[i]!= ']') {

            if (!isdigit(s[i])) {
                res += s[i];
                i++;
            }

            else {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num*10 + s[i] - '0';
                    i++;
                }

                i++; // skip over [
                string t = helper(s,i);
                i++; // skip over ]

                while(num-- > 0)
                    res += t;

            }
        }

        return res;

    }



public:
    string decodeString(string s) {

      int i = 0;
      return helper(s,i);

    }
};
