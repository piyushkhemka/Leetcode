class Solution {

    int helper(const string &word1, int a, const string &word2, int b, vector<vector<int> > &dist) {

        if (a < 0)
            return b+1;

        else if (b < 0)
            return a+1;

        if (dist[a][b] == -1) {

            if (word1[a] == word2[b])

                dist[a][b] = helper(word1, a-1, word2, b-1, dist);

            else {

                int sub = helper(word1, a-1, word2, b-1, dist);
                int add = helper(word1, a-1, word2, b, dist);
                int del = helper(word1, a, word2, b-1, dist);

                dist[a][b] = 1 + min(min(sub,add),del);

            }
        }
        return dist[a][b];
    }


public:
    int minDistance(string word1, string word2) {

        int a = word1.length()-1;
        int b = word2.length()-1;

        vector<vector<int> > dist(a+1, vector<int> (b+1, -1));

        return helper(word1, a, word2, b, dist);

    }
};
