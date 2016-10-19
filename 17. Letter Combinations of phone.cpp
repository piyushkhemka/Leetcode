class Solution {
public:


    void perletter(unordered_map<char, vector<char> > &m, vector<string> &result, int cursize, const string &digits,const string &curcombination ) {

        if (cursize == digits.length()) {
            result.push_back(curcombination);
            return;
        }

      //  for(int i = cursize;i<digits.length();i++) {
      int i = cursize;
            for(auto j = m[digits[i]].begin(); j!= m[digits[i]].end() ; j++) {
                char let = *j;
                perletter(m,result,cursize+1, digits, curcombination+let);

            }
        }


    vector<string> letterCombinations(string digits) {

        unordered_map<char, vector<char> > m {
                                               {'2',{'a','b','c'}}, {'4',{'g','h','i'}},
                                               {'3',{'d','e','f'}}, {'5',{'j','k','l'}},
                                               {'6',{'m','n','o'}}, {'7',{'p','q','r','s'}},
                                               {'8',{'t','u','v'}}, {'9',{'w','x','y','z'}},
                                               {'0',{}}


                                             };



            vector<string> result;
             if(digits.size() < 1)
                return result;
            perletter(m, result, 0, digits, "");


            return result;


    }
};
