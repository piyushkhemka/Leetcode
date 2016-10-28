class Solution {

private:
    void lexical(int n, vector<int> &result, int k) {

        if (k > n)
            return;

        if (k)
            result.push_back(k);

        for(int i = 0;i<= 9; ++i) {

            if(k == 0 && i==0)
                continue;

            if ((k*10 + i) > n)
               break;

            lexical(n, result, k*10 + i);



        }



    }
public:
    vector<int> lexicalOrder(int n) {

        vector<int> result;
        lexical(n,result,0);
        return result;


    }
};
