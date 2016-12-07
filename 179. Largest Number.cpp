class Solution {

    struct mycomp {

      bool operator ()(const string &s1, const string &s2) {

         return s1+s2 > s2+s1;

      }



    };

public:
    string largestNumber(vector<int>& nums) {

        vector<string> numstring;

        for(auto i: nums) {
            numstring.push_back(to_string(i));
        }

        sort(numstring.begin(), numstring.end(), mycomp);

        string res = "";

        for(auto s : numstring)
            res += s;

        if(res[0] == '0')
            res = "0";

        return res;

    }
};


// -----

// With lambdas


class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> numstring;

        for(auto i: nums) {
            numstring.push_back(to_string(i));
        }

        sort(numstring.begin(), numstring.end(), [] (const string &s1, const string &s2) { return s1+s2 > s2+s1; });

        string res = "";

        for(auto s : numstring)
            res += s;

        if(res[0] == '0')
            res = "0";

        return res;

    }
};
